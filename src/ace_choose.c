#include "global.h"
#include "ace_choose.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define ACE_MON_COUNT 18

// Position of the sprite of the selected ace Pokémon
#define ACE_PKMN_POS_X (DISPLAY_WIDTH / 5)
#define ACE_PKMN_POS_Y 64

#define TAG_POKEBALL_SELECT 0x1000
#define TAG_ACE_CIRCLE 0x1001

static void CB2_AceChoose(void);
static void ClearAceLabel(void);
static void Task_AceChoose(u8 taskId);
static void Task_HandleAceChooseInput(u8 taskId);
static void Task_WaitForAceSprite(u8 taskId);
static void Task_AskConfirmAce(u8 taskId);
static void Task_HandleConfirmAceInput(u8 taskId);
static void Task_DeclineAce(u8 taskId);
static void Task_MoveAceChooseCursor(u8 taskId);
static void Task_CreateAceLabel(u8 taskId);
static void CreateAcePokemonLabel(u8 selection);
static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y);
static void SpriteCB_SelectionHand(struct Sprite *sprite);
static void SpriteCB_Pokeball(struct Sprite *sprite);
static void SpriteCB_AcePokemon(struct Sprite *sprite);

static u16 sAceLabelWindowId;

// TODO: move to ace_choose graphics folder
const u16 gAceBirchBagGrass_Pal[] = INCBIN_U16("graphics/starter_choose/tiles.gbapal");
static const u16 sPokeballSelection_Pal[] = INCBIN_U16("graphics/starter_choose/pokeball_selection.gbapal");
static const u16 sAceCircle_Pal[] = INCBIN_U16("graphics/starter_choose/starter_circle.gbapal");
const u32 gAceBirchBagTilemap[] = INCBIN_U32("graphics/starter_choose/birch_bag.bin.lz");
const u32 gAceBirchGrassTilemap[] = INCBIN_U32("graphics/starter_choose/birch_grass.bin.lz");
const u32 gAceBirchBagGrass_Gfx[] = INCBIN_U32("graphics/starter_choose/tiles.4bpp.lz");
const u32 gAcePokeballSelection_Gfx[] = INCBIN_U32("graphics/starter_choose/pokeball_selection.4bpp.lz");
static const u32 sAceCircle_Gfx[] = INCBIN_U32("graphics/starter_choose/starter_circle.4bpp.lz");

static const struct WindowTemplate sWindowTemplates[] =
    {
        {.bg = 0,
         .tilemapLeft = 3,
         .tilemapTop = 15,
         .width = 24,
         .height = 4,
         .paletteNum = 14,
         .baseBlock = 0x0200},
        DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sWindowTemplate_ConfirmAce =
    {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0260};

static const struct WindowTemplate sWindowTemplate_AceLabel =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 13,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0274};

static const u8 sPokeballCoords[ACE_MON_COUNT][2] =
    {
        {16, 32},
        {32, 64},
        {48, 32},
        {64, 64},
        {80, 32},
        {96, 64},
        {112, 32},
        {128, 64},
        {144, 32},
        {160, 64},
        {176, 32},
        {192, 64},
        {16, 98},
        {48, 98},
        {80, 98},
        {112, 98},
        {144, 98},
        {176, 98}};

// single-type only, prioritizing non-evo
static const u16 sAceMon[ACE_MON_COUNT] =
    {
        SPECIES_BOUFFALANT, // normal
        SPECIES_PASSIMIAN,  // fighting
        SPECIES_CHATOT,     // flying - dual type
        SPECIES_SEVIPER,    // poison
        SPECIES_MUDBRAY,    // ground
        SPECIES_KLAWF,      // rock
        SPECIES_PINSIR,     // bug
        SPECIES_GIMMIGHOUL, // ghost
        SPECIES_ORTHWORM,   // steel
        SPECIES_HEATMOR,    // fire
        SPECIES_PYUKUMUKU,  // water
        SPECIES_MARACTUS,   // grass
        SPECIES_PINCURCHIN, // electric
        SPECIES_ELGYEM,     // psychic - evolves
        SPECIES_CRYOGONAL,  // ice
        SPECIES_DRUDDIGON,  // dragon
        SPECIES_ABSOL,      // dark
        SPECIES_COMFEY,     // fairy
};

static const struct BgTemplate sBgTemplates[3] =
    {
        {.bg = 0,
         .charBaseIndex = 2,
         .mapBaseIndex = 31,
         .screenSize = 0,
         .paletteMode = 0,
         .priority = 0,
         .baseTile = 0},
        {.bg = 2,
         .charBaseIndex = 0,
         .mapBaseIndex = 7,
         .screenSize = 0,
         .paletteMode = 0,
         .priority = 3,
         .baseTile = 0},
        {.bg = 3,
         .charBaseIndex = 0,
         .mapBaseIndex = 6,
         .screenSize = 0,
         .paletteMode = 0,
         .priority = 1,
         .baseTile = 0},
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};

static const struct OamData sOam_Hand =
    {
        .y = DISPLAY_HEIGHT,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(32x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(32x32),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
};

static const struct OamData sOam_Pokeball =
    {
        .y = DISPLAY_HEIGHT,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(32x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(32x32),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
};

static const struct OamData sOam_AceCircle =
    {
        .y = DISPLAY_HEIGHT,
        .affineMode = ST_OAM_AFFINE_DOUBLE,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(64x64),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(64x64),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
};

static const u8 sCursorCoords[ACE_MON_COUNT][2] =
    {
        {16, 0},
        {32, 24},
        {48, 0},
        {64, 24},
        {80, 0},
        {96, 24},
        {112, 0},
        {128, 24},
        {144, 0},
        {160, 24},
        {176, 0},
        {192, 24},
        {16, 58},
        {48, 58},
        {80, 58},
        {112, 58},
        {144, 58},
        {176, 58}};

static const union AnimCmd sAnim_Hand[] =
    {
        ANIMCMD_FRAME(48, 30),
        ANIMCMD_END,
};

static const union AnimCmd sAnim_Pokeball_Still[] =
    {
        ANIMCMD_FRAME(0, 30),
        ANIMCMD_END,
};

static const union AnimCmd sAnim_Pokeball_Moving[] =
    {
        ANIMCMD_FRAME(16, 4),
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(32, 4),
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(16, 4),
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(32, 4),
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(0, 32),
        ANIMCMD_FRAME(16, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(32, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(16, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(32, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_AceCircle[] =
    {
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Hand[] =
    {
        sAnim_Hand,
};

static const union AnimCmd *const sAnims_Pokeball[] =
    {
        sAnim_Pokeball_Still,
        sAnim_Pokeball_Moving,
};

static const union AnimCmd *const sAnims_AceCircle[] =
    {
        sAnim_AceCircle,
};

static const union AffineAnimCmd sAffineAnim_AcePokemon[] =
    {
        AFFINEANIMCMD_FRAME(16, 16, 0, 0),
        AFFINEANIMCMD_FRAME(16, 16, 0, 15),
        AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_AceCircle[] =
    {
        AFFINEANIMCMD_FRAME(20, 20, 0, 0),
        AFFINEANIMCMD_FRAME(20, 20, 0, 15),
        AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_AcePokemon = {sAffineAnim_AcePokemon};
static const union AffineAnimCmd *const sAffineAnims_AceCircle[] = {sAffineAnim_AceCircle};

static const struct CompressedSpriteSheet sSpriteSheet_PokeballSelect[] =
    {
        {.data = gAcePokeballSelection_Gfx,
         .size = 0x0800,
         .tag = TAG_POKEBALL_SELECT},
        {}};

static const struct CompressedSpriteSheet sSpriteSheet_AceCircle[] =
    {
        {.data = sAceCircle_Gfx,
         .size = 0x0800,
         .tag = TAG_ACE_CIRCLE},
        {}};

static const struct SpritePalette sSpritePalettes_AceChoose[] =
    {
        {.data = sPokeballSelection_Pal,
         .tag = TAG_POKEBALL_SELECT},
        {.data = sAceCircle_Pal,
         .tag = TAG_ACE_CIRCLE},
        {},
};

static const struct SpriteTemplate sSpriteTemplate_Hand =
    {
        .tileTag = TAG_POKEBALL_SELECT,
        .paletteTag = TAG_POKEBALL_SELECT,
        .oam = &sOam_Hand,
        .anims = sAnims_Hand,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_SelectionHand};

static const struct SpriteTemplate sSpriteTemplate_Pokeball =
    {
        .tileTag = TAG_POKEBALL_SELECT,
        .paletteTag = TAG_POKEBALL_SELECT,
        .oam = &sOam_Pokeball,
        .anims = sAnims_Pokeball,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_Pokeball};

static const struct SpriteTemplate sSpriteTemplate_AceCircle =
    {
        .tileTag = TAG_ACE_CIRCLE,
        .paletteTag = TAG_ACE_CIRCLE,
        .oam = &sOam_AceCircle,
        .anims = sAnims_AceCircle,
        .images = NULL,
        .affineAnims = sAffineAnims_AceCircle,
        .callback = SpriteCB_AcePokemon};

// .text
u16 GetAcePokemon(u16 chosenAceId)
{
    if (chosenAceId > ACE_MON_COUNT)
        chosenAceId = 0;
    return sAceMon[chosenAceId];
}

static void VblankCB_AceChoose(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Data for Task_AceChoose
#define tAceSelection data[0]
#define tPkmnSpriteId data[1]
#define tCircleSpriteId data[2]

// Data for sSpriteTemplate_Pokeball
#define sTaskId data[0]
#define sBallId data[1]

void CB2_ChooseAce(void)
{
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gAceBirchBagGrass_Gfx, (void *)VRAM);
    LZ77UnCompVram(gAceBirchBagTilemap, (void *)(BG_SCREEN_ADDR(6)));
    LZ77UnCompVram(gAceBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(gAceBirchBagGrass_Pal, BG_PLTT_ID(0), sizeof(gAceBirchBagGrass_Pal));
    LoadCompressedSpriteSheet(&sSpriteSheet_PokeballSelect[0]);
    LoadCompressedSpriteSheet(&sSpriteSheet_AceCircle[0]);
    LoadSpritePalettes(sSpritePalettes_AceChoose);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_AceChoose);
    SetMainCallback2(CB2_AceChoose);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    taskId = CreateTask(Task_AceChoose, 0);
    gTasks[taskId].tAceSelection = 0;

    // Create hand sprite
    spriteId = CreateSprite(&sSpriteTemplate_Hand, 120, 56, 2);
    gSprites[spriteId].data[0] = taskId;

    // Create Poké Ball sprites
    int i = 0;
    for (i = 0; i < ACE_MON_COUNT; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Pokeball, sPokeballCoords[i][0], sPokeballCoords[i][1], 2);
        gSprites[spriteId].sTaskId = taskId;
        gSprites[spriteId].sBallId = i;
    }

    sAceLabelWindowId = WINDOW_NONE;
}

static void CB2_AceChoose(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_AceChoose(u8 taskId)
{
    CreateAcePokemonLabel(gTasks[taskId].tAceSelection);
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_AceSelection, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_HandleAceChooseInput;
}

static void Task_HandleAceChooseInput(u8 taskId)
{
    u8 selection = gTasks[taskId].tAceSelection;

    if (JOY_NEW(A_BUTTON))
    {
        u8 spriteId;

        ClearAceLabel();

        // Create white circle background
        spriteId = CreateSprite(&sSpriteTemplate_AceCircle, sPokeballCoords[selection][0], sPokeballCoords[selection][1], 1);
        gTasks[taskId].tCircleSpriteId = spriteId;

        // Create Pokémon sprite
        spriteId = CreatePokemonFrontSprite(GetAcePokemon(gTasks[taskId].tAceSelection), sPokeballCoords[selection][0], sPokeballCoords[selection][1]);
        gSprites[spriteId].affineAnims = &sAffineAnims_AcePokemon;
        gSprites[spriteId].callback = SpriteCB_AcePokemon;

        gTasks[taskId].tPkmnSpriteId = spriteId;
        gTasks[taskId].func = Task_WaitForAceSprite;
    }
    else if (JOY_NEW(DPAD_LEFT) && selection > 0)
    {
        gTasks[taskId].tAceSelection--;
        gTasks[taskId].func = Task_MoveAceChooseCursor;
    }
    else if (JOY_NEW(DPAD_RIGHT) && selection < ACE_MON_COUNT - 1)
    {
        gTasks[taskId].tAceSelection++;
        gTasks[taskId].func = Task_MoveAceChooseCursor;
    }
}

static void Task_WaitForAceSprite(u8 taskId)
{
    if (gSprites[gTasks[taskId].tCircleSpriteId].affineAnimEnded &&
        gSprites[gTasks[taskId].tCircleSpriteId].x == ACE_PKMN_POS_X &&
        gSprites[gTasks[taskId].tCircleSpriteId].y == ACE_PKMN_POS_Y)
    {
        gTasks[taskId].func = Task_AskConfirmAce;
    }
}

static void Task_AskConfirmAce(u8 taskId)
{
    PlayCry_Normal(GetAcePokemon(gTasks[taskId].tAceSelection), 0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ConfirmAceChoice, 0, 1, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    CreateYesNoMenu(&sWindowTemplate_ConfirmAce, 0x2A8, 0xD, 0);
    gTasks[taskId].func = Task_HandleConfirmAceInput;
}

static void Task_HandleConfirmAceInput(u8 taskId)
{
    u8 spriteId;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // YES
        // Return the ace choice and exit.
        gSpecialVar_Result = gTasks[taskId].tAceSelection;
        ResetAllPicSprites();
        SetMainCallback2(gMain.savedCallback);
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        spriteId = gTasks[taskId].tPkmnSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        FreeAndDestroyMonPicSprite(spriteId);

        spriteId = gTasks[taskId].tCircleSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        gTasks[taskId].func = Task_DeclineAce;
        break;
    }
}

static void Task_DeclineAce(u8 taskId)
{
    gTasks[taskId].func = Task_AceChoose;
}

static void CreateAcePokemonLabel(u8 selection)
{
    u8 categoryText[32];
    struct WindowTemplate winTemplate;
    const u8 *speciesName;
    s32 width;
    u8 labelLeft, labelRight, labelTop, labelBottom;

    u16 species = GetAcePokemon(selection);
    CopyMonCategoryText(species, categoryText);
    speciesName = GetSpeciesName(species);

    winTemplate = sWindowTemplate_AceLabel;
    winTemplate.tilemapLeft = 16;
    winTemplate.tilemapTop = 10;

    sAceLabelWindowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(sAceLabelWindowId, PIXEL_FILL(0));

    width = GetStringCenterAlignXOffset(FONT_NARROW, categoryText, 0x68);
    AddTextPrinterParameterized3(sAceLabelWindowId, FONT_NARROW, width, 1, sTextColors, 0, categoryText);

    width = GetStringCenterAlignXOffset(FONT_NORMAL, speciesName, 0x68);
    AddTextPrinterParameterized3(sAceLabelWindowId, FONT_NORMAL, width, 17, sTextColors, 0, speciesName);

    PutWindowTilemap(sAceLabelWindowId);
    ScheduleBgCopyTilemapToVram(0);

    labelLeft = 16 * 8 - 4;
    labelRight = (16 + 13) * 8 + 4;
    labelTop = 10 * 8;
    labelBottom = (10 + 4) * 8;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(labelLeft, labelRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(labelTop, labelBottom));
}

static void ClearAceLabel(void)
{
    FillWindowPixelBuffer(sAceLabelWindowId, PIXEL_FILL(0));
    ClearWindowTilemap(sAceLabelWindowId);
    RemoveWindow(sAceLabelWindowId);
    sAceLabelWindowId = WINDOW_NONE;
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_MoveAceChooseCursor(u8 taskId)
{
    ClearAceLabel();
    gTasks[taskId].func = Task_CreateAceLabel;
}

static void Task_CreateAceLabel(u8 taskId)
{
    CreateAcePokemonLabel(gTasks[taskId].tAceSelection);
    gTasks[taskId].func = Task_HandleAceChooseInput;
}

static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreateMonPicSprite_Affine(species, FALSE, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

static void SpriteCB_SelectionHand(struct Sprite *sprite)
{
    // Float up and down above selected Poké Ball
    sprite->x = sCursorCoords[gTasks[sprite->data[0]].tAceSelection][0];
    sprite->y = sCursorCoords[gTasks[sprite->data[0]].tAceSelection][1];
    sprite->y2 = Sin(sprite->data[1], 8);
    sprite->data[1] = (u8)(sprite->data[1]) + 4;
}

static void SpriteCB_Pokeball(struct Sprite *sprite)
{
    // Animate Poké Ball if currently selected
    if (gTasks[sprite->sTaskId].tAceSelection == sprite->sBallId)
        StartSpriteAnimIfDifferent(sprite, 1);
    else
        StartSpriteAnimIfDifferent(sprite, 0);
}

static void SpriteCB_AcePokemon(struct Sprite *sprite)
{
    // Move sprite to upper center of screen
    if (sprite->x > ACE_PKMN_POS_X)
        sprite->x -= 4;
    if (sprite->x < ACE_PKMN_POS_X)
        sprite->x += 4;
    if (sprite->y > ACE_PKMN_POS_Y)
        sprite->y -= 2;
    if (sprite->y < ACE_PKMN_POS_Y)
        sprite->y += 2;
}
