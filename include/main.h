#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

#define NUM_SPRITE_GROUPS 100
#define MAX_SPRITES_IN_GROUP 22

typedef void (*StateFunc)(void);
typedef void (*IntrFunc)(void);

struct MainUnk2E8
{
    u16 unk0;
    u16 unk2;
};

struct SpriteSet
{
    u16 count;
    u8 oamData[0];
};

struct OamDataSimple
{
    u16 oamId;
    s16 xOffset;
    s16 yOffset;
};

struct SpriteGroup
{
    u16 available;
    s16 baseX;
    s16 baseY;
    struct OamDataSimple oam[MAX_SPRITES_IN_GROUP];
};
// size: 0xB8

struct Main
{
    /*0x00*/ u8 filler0[0x2];
    /*0x02*/ u8 mainState;
    /*0x03*/ u8 subState;
    /*0x04*/ u8 unk4;
    /*0x05*/ u8 filler5[0x2];
    /*0x07*/ s8 unk7;
    /*0x08*/ s8 unk8;
    /*0x09*/ u8 filler9[0x4];
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 fillerE[0x1];
    /*0x0F*/ u8 unkF;
    /*0x10*/ u8 unk10;
    /*0x11*/ u8 unk11;
    /*0x12*/ s16 unk12;
    /*0x14*/ s16 unk14;
    /*0x16*/ u16 unk16;
    /*0x18*/ u16 newKeys;
    /*0x1A*/ u16 releasedKeys;
    /*0x1C*/ u16 heldKeys;
    /*0x1E*/ u8 filler1E[0x2];
    /*0x20*/ u16 unk20;
    /*0x22*/ u8 filler22[0x4];
    /*0x26*/ s16 vCount;
    /*0x28*/ s16 unk28;
    /*0x2A*/ s16 unk2A;
    /*0x2C*/ s16 unk2C;
    /*0x2E*/ u8 filler2E[0x2];
    /*0x30*/ u16 unk30;
    /*0x32*/ u8 filler32[0x4];
    /*0x36*/ u8 unk36;
    /*0x38*/ volatile u16 blendControl;
    /*0x3A*/ volatile u16 blendAlpha;
    /*0x3C*/ volatile u16 blendBrightness;
    /*0x40*/ int unk40;
    /*0x44*/ u8 filler44[0x4];
    /*0x48*/ int rngValue;
    /*0x4C*/ int unk4C;
    /*0x50*/ int unk50;
    /*0x54*/ u8 filler54[0x20];
    /*0x74*/ u8 pokedexFlags[204];
    /*0x140*/ u8 filler140[0x1A8];
    /*0x2E8*/ struct MainUnk2E8 unk2E8[4];
    /*0x2F8*/ struct SpriteGroup spriteGroups[NUM_SPRITE_GROUPS];
};


extern struct Main gMain;
extern u8 gUnknown_0200B134[];
extern struct SpriteGroup gUnknown_0200B3B8[];
extern u32 IntrMain_Buffer[0x200];
extern u32 IntrMain[];
extern IntrFunc *gUnknown_0200FB98;
extern IntrFunc *gUnknown_02019BE0;
extern int gUnknown_02019BE4;
extern int gUnknown_02019BE8;
extern int gUnknown_02019BEC;
extern u32 gUnknown_02019BF0;
extern int gUnknown_02019BF4;
extern int gUnknown_02019BF8;
extern int gUnknown_02019BFC;
extern int gUnknown_02019C00;
extern int gUnknown_02019C04;
extern int gUnknown_02019C08;
extern int gGameBoyPlayerEnabled;
extern u8 gUnknown_02019C10;
extern u8 gUnknown_02002008[];
#define INTR_COUNT 14
extern IntrFunc gIntrTable[14];
extern void (*gUnknown_0200FB9C)(void);
extern void (*gUnknown_0200FBA0)(void);
extern void (*gUnknown_02017BD0)(void);
extern void (*gUnknown_02017BD4)(void);
extern StateFunc gMainFuncs[];
extern struct OamData gOamBuffer[128];
extern u16 gUnknown_03005C00[0x600];

void SetMainGameState(u16);
void sub_24C(void);
void sub_2B4(void);
void sub_490(void);
void sub_518(void);
void sub_578(void);
u32 Random(void);
void sub_CBC(void);
void sub_D10(void);
void sub_D74(void);
void SerialIntr(void);
void Timer3Intr(void);
s16 LoadSpriteSets(const struct SpriteSet* const*, u16, struct SpriteGroup*);

#endif // GUARD_MAIN_H
