#include "global.h"
#include "main.h"

extern IntrFunc *gUnknown_0200FB98;
extern IntrFunc *gUnknown_02019BE0;
extern void (*gUnknown_0200FB9C)(void);
extern void (*gUnknown_0200FBA0)(void);
extern void (*gUnknown_02017BD0)(void);
extern void (*gUnknown_02017BD4)(void);
extern void HBlankIntr(void);
extern void VCountIntr(void);
extern void sub_DC4(void);

u16 sub_850(void)
{
    if (REG_IME & INTR_FLAG_VBLANK
     && REG_DISPSTAT & DISPSTAT_VBLANK_INTR
     && REG_IE & INTR_FLAG_VBLANK
     && !(REG_DISPCNT & DISPCNT_FORCED_BLANK))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void sub_898(void (*func)(void))
{
    gUnknown_02017BD4 = func;
    if (!sub_850())
        gUnknown_0200FB9C = func;
}

void sub_8BC(void)
{
    gUnknown_0200FB9C = sub_DC4;
    gUnknown_02017BD4 = sub_DC4;
}

void sub_8D4(void (*func)(void))
{
    gUnknown_02017BD0 = func;
    if (!sub_850())
        *gUnknown_0200FB98 = func;
}

void sub_8FC(void)
{
    *gUnknown_0200FB98 = HBlankIntr;
    gUnknown_02017BD0 = HBlankIntr;
}

void sub_918(void (*func)(void))
{
    gUnknown_0200FBA0 = func;
    if (!sub_850())
        *gUnknown_02019BE0 = func;
}

void sub_940(void)
{
    *gUnknown_02019BE0 = VCountIntr;
    gUnknown_0200FBA0 = VCountIntr;
}

