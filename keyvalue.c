#include "keyvalue.h"

JOYSTICK GA003 =
{
    .A = 0x0130,
    .B = 0x0131,
    .X = 0x0133,
    .Y = 0x0134,
    .LB = 0x0136,
    .RB = 0x0137,
    .LT = 0x0138,
    .RT = 0x0139,
    .SELECT = 0x013a,
    .MENU = 0x013b,
    .HOME = 0x013c,
    .press = 0x00000001,
    .L_STICK = 
    {
        .x_axis = 0x00,
        .y_axis = 0x01,
        .press = 0x013d,
    },
    .R_STICK = 
    {
        .x_axis = 0x02,
        .y_axis = 0x05,
        .press = 0x013e,
    },
    .PAD = 
    {
        .x_axis = 0x10,
        .y_axis = 0x11,
        .uol = 0xFFFFFFFF,
        .dor = 0x00000001,
    },
};
JOYSTICK *new_joystick()
{
    return &GA003;
}


