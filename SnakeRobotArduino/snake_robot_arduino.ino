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


#include "snake_robot.h"
#include "cal_optimize.h"
#include "cal_amplitude.h"
#include "cal_phase.h"
#include "cal_position.h"
#include "servo_run.h"

SnakeRobot snake_robot;
SnakeRobot* snake_robot_ptr = &snake_robot; //指针初始化

// the setup function runs once when you press reset or power the board
void setup() 
{
	//串口初始化
	Serial.begin(9600); //串口0通讯波特率
	Serial1.begin(115200); //串口1通讯波特率
	Serial2.begin(115200); //串口2通讯波特率
	Serial3.begin(115200); //串口3通讯波特率

	//参数初始化
	snake_robot.time_interval = 100; //间隔ms

	snake_robot.link_y = 0.1;
	snake_robot.link_p = 0.1;

	snake_robot.lamda_y = 0.25;
	snake_robot.lamda_p = 0.25;
	
	snake_robot.direction_y = 1;
	snake_robot.direction_p = -1;

	//默认模式1
	snake_robot.mode = 1;

	snake_robot.wave_a0_y = 50.0;
	snake_robot.wave_a0_p = 10.0;
	snake_robot.wave_kn = 2;

	snake_robot.cshape_r = 1;

	snake_robot.spiral_r = 0.5;
	snake_robot.spiral_p = 0.2;

	//舵机编号赋值并初始化
	for (int i = 0; i < snake_robot_ptr->joint_n; i++)
	{
		snake_robot.snake_joints[i].id_y = 2 * (i + 1) - 1;
		snake_robot.snake_joints[i].id_p = 2 * (i + 1);
		sprintf(snake_robot.cmd_return, "{#%03dP1500T2000!#%03dP1500T2000!}", snake_robot.snake_joints[i].id_y, snake_robot.snake_joints[i].id_p);
		if (i >= 0 && i <= 4)
		{
			Serial2.print(snake_robot.cmd_return);
		}
		else if (i >= 5 && i <= 9)
		{
			Serial3.print(snake_robot.cmd_return);
		}
	}
	delay(3000);

	//运行时间初始化
	snake_robot.time_start = millis();
	snake_robot.time_current = snake_robot.time_start; //获取当前时刻
}

// the loop function runs over and over again until power down or reset
void loop()
{
	if ((millis() - snake_robot.time_current) >= snake_robot.time_interval)
	{
		//程序时间
		snake_robot.time_current = millis(); //获取当前时刻
		snake_robot.time_run = (snake_robot.time_current - snake_robot.time_start) * 1.0 / 1000; //秒

		//计算幅值和相位差
		cal_optimize(snake_robot_ptr);
		cal_amplitude(snake_robot_ptr);
		cal_phase(snake_robot_ptr);
		cal_position(snake_robot_ptr);

		//运行舵机
		servo_run(snake_robot_ptr);
	}
}
