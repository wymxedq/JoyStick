#ifndef _KEY_VALUE
#define _KEY_VALUE

typedef unsigned short u16;
typedef signed int s32;

/* 摇杆 */
typedef struct 
{
    u16 x_axis;
    u16 y_axis;
    u16 press;  //摇杆按下的键码
}STICK;

/* 十字方向键 */
typedef struct
{
    u16 x_axis;
    u16 y_axis;
    s32 uol;    //上键或左键键值
    s32 dor;    //下键或右键键值
}CROSS;

typedef struct 
{
    u16 A;
    u16 B;
    u16 X;
    u16 Y;
    u16 LB;
    u16 RB;
    u16 LT;
    u16 RT;
    u16 SELECT;
    u16 MENU;
    u16 HOME;
    s32 press;      //按键按下的键值
    STICK L_STICK;  //左摇杆
    STICK R_STICK;  //右摇杆
    CROSS PAD;      //十字方向键

}JOYSTICK;

JOYSTICK *new_joystick(void);

#endif



