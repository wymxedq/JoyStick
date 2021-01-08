#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include "keyvalue.h"

int main()
{
    int joystick_fd,ret;
    struct input_event joystick_data;
    JOYSTICK *ex;

    ex = new_joystick();
    joystick_fd = open("/dev/input/event0",O_RDONLY);
    if(joystick_fd < 0)
    {
        perror("open");
    }
    printf("Open device file success\n");

    while(1)
    {
        ret = read(joystick_fd,&joystick_data,sizeof(joystick_data));
        if(ret < sizeof(joystick_data))
        {
            perror("read");
            continue;
        }
        if(joystick_data.type == EV_KEY)
        {
            //判断操作的按键
            if(joystick_data.code == ex->A)
                printf("A键");
            else if(joystick_data.code == ex->B)
                printf("B键");
            else if(joystick_data.code == ex->X)
                printf("X键");
            else if(joystick_data.code == ex->Y)
                printf("Y键");
            else if(joystick_data.code == ex->LB)
                printf("左肩键");
            else if(joystick_data.code == ex->RB)
                printf("右肩键");
            else if(joystick_data.code == ex->LT)
                printf("左扳机键");
            else if(joystick_data.code == ex->RT)
                printf("右扳机键");
            else if(joystick_data.code == ex->SELECT)
                printf("选择键");
            else if(joystick_data.code == ex->MENU)
                printf("菜单键");
            else if(joystick_data.code == ex->HOME)
                printf("中键");
            else if(joystick_data.code == ex->L_STICK.press)
                printf("左摇杆");
            else if(joystick_data.code == ex->R_STICK.press)
                printf("右摇杆");
            //判断是否为按下操作
            if(joystick_data.value == ex->press)
                printf("按下\n");
            else
                printf("松开\n");
        }
        else if(joystick_data.type == EV_ABS)
        {
            //四向按键按下
            if(joystick_data.code == ex->PAD.y_axis)
            {
                //上下键
                if(joystick_data.value == ex->PAD.uol)
                    printf("上键按下\n");
                else if(joystick_data.value == ex->PAD.dor)
                    printf("下键按下\n");
                else
                    printf("松开\n");
            }
            else if(joystick_data.code == ex->PAD.x_axis)
            {
                //左右键
                if(joystick_data.value == ex->PAD.uol)
                    printf("左键按下\n");
                else if(joystick_data.value == ex->PAD.dor)
                    printf("右键按下\n");
                else
                    printf("松开\n");
            }
            //摇杆推动
            //右摇杆y轴
            else if(joystick_data.code == ex->R_STICK.y_axis)
            {
                if(joystick_data.value < 128)
                    printf("右摇杆向上推动%d\n",128 - joystick_data.value);
                else if(joystick_data.value == 128)
                    printf("右摇杆y轴归位\n");
                else if(joystick_data.value > 128)
                    printf("右摇杆向下推动%d\n",joystick_data.value - 128);
            }
            //右摇杆x轴
            else if(joystick_data.code == ex->R_STICK.x_axis)
            {
                if(joystick_data.value < 128)
                    printf("右摇杆向左推动%d\n",128 - joystick_data.value);
                else if(joystick_data.value == 128)
                    printf("右摇杆x轴归位\n");
                else if(joystick_data.value > 128)
                    printf("右摇杆向右推动%d\n",joystick_data.value - 128);
            }
            //左摇杆x轴
            else if(joystick_data.code == ex->L_STICK.x_axis)
            {
                if(joystick_data.value < 128)
                    printf("左摇杆向左推动%d\n",128 - joystick_data.value);
                else if(joystick_data.value == 128)
                    printf("左摇杆x轴归位\n");
                else if(joystick_data.value > 128)
                    printf("左摇杆向右推动%d\n",joystick_data.value - 128);
            }
            //左摇杆y轴
            else if(joystick_data.code == ex->L_STICK.y_axis)
            {
                if(joystick_data.value < 128)
                    printf("左摇杆向上推动%d\n",128 - joystick_data.value);
                else if(joystick_data.value == 128)
                    printf("左摇杆y轴归位\n");
                else if(joystick_data.value > 128)
                    printf("左摇杆向下推动%d\n",joystick_data.value - 128);
            }
        }
    }
    return 0;
}


