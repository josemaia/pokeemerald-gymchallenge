#ifndef GUARD_ACE_CHOOSE_H
#define GUARD_ACE_CHOOSE_H

extern const u16 gAceBirchBagGrass_Pal[];
extern const u32 gAceBirchBagTilemap[];
extern const u32 gAceBirchGrassTilemap[];
extern const u32 gAceBirchBagGrass_Gfx[];
extern const u32 gAcePokeballSelection_Gfx[];

u16 GetAcePokemon(u16 chosenAceId);
void CB2_ChooseAce(void);

#endif // GUARD_ACE_CHOOSE_H
