/*
========================================================================================================================

* This file is part of SnakeRobotSerpenoid
*
* Copyright (C) 2018-2024 Xupeng Liu.
*
* SnakeRobotSerpenoid is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
*
* SnakeRobotSerpenoid is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
* the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with SnakeRobotSerpenoid.
* If not, see <http://www.gnu.org/licenses/>.

========================================================================================================================
*/


#include <wiringPi.h>
#include <wiringSerial.h>
#include <iostream>

#include "snake_joint.h"
#include "snake_body.h"
#include "snake_init.h"
#include "snake_motion_1.h"
#include "snake_motion_2.h"
#include "snake_motion_3.h"
#include "snake_motion_4.h"
#include "snake_servo_run.h"

int main() {
    wiringPiSetupSys();

    int ser; //串口描述符

    // 时间变量
    unsigned int time_start; //起始时间 ms
    unsigned int time_current; //当前时间 ms
    unsigned int time_interval; //运动离散时间间隔 ms
    double time_run; //运行时间 s

    time_interval = 50; //间隔ms

    //打开USB串口
    ser = serialOpen("/dev/ttyUSB0", 115200);
    serialFlush(ser);

    //蛇形机器人实例化
    SnakeBody Snake(11); //初始化为11节蛇形机器人结构
    SnakeBody *SnakePtr = &Snake; //初始化指针

    //初始化
    SnakeInit(SnakePtr, ser);
    delay(3000);

    //运行时间初始化
    time_start = millis();
    time_current = time_start; //获取当前时刻

    while (true) {
        if ((millis() - time_current) >= time_interval) {
            //程序时间
            time_current = millis();
            time_run = (time_current - time_start) * 1.0 / 1000;

            //模式控制
            switch (Snake.mode) {
                case 1: {
                    SnakeMotion1(SnakePtr, time_run);
                    break;
                }

                case 2: {
                    SnakeMotion2(SnakePtr, time_run);
                    break;
                }

                case 3: {
                    SnakeMotion3(SnakePtr, time_run);
                    break;
                }

                case 4: {
                    SnakeMotion4(SnakePtr, time_run, 10.0 / 180.0 * M_PI);
                    break;
                }

                default:
                    break;
            }

            //运行舵机
            SnakeServoRun(ser, SnakePtr, time_run, time_interval);
        }
    }

    serialFlush(ser);
    serialClose(ser);

    return 0;
}
