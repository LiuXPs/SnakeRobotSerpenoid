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


#ifndef SNAKE_INIT_H
#define SNAKE_INIT_H

#pragma once
#include <cmath>
#include "snake_joint.h"
#include "snake_body.h"

void SnakeInit(SnakeBody* snake_ptr, int ser)
{
	//参数初始化
	snake_ptr->snake_L_x = 0.1059025;
	snake_ptr->snake_L_y = 0.1059025;
	snake_ptr->lamda_x = 0.25;
	snake_ptr->lamda_y = 0.25;
	snake_ptr->mode = 1;

	snake_ptr->snake_A0_x = 30.0;
	snake_ptr->snake_Kn_x = 3 * 1.0;
	snake_ptr->snake_T_x = 10 * 1.0;
	snake_ptr->snake_E_x = 0.0;

	snake_ptr->snake_A0_y = 10.0;
	snake_ptr->snake_Kn_y = snake_ptr->snake_Kn_x;
	snake_ptr->snake_T_y = snake_ptr->snake_T_x;
	snake_ptr->snake_E_y = 0.0;

	//舵机编号赋值与位置初始化
	for (int i = 0; i < snake_ptr->snake_n - 1; i++)
	{
		SnakeJoint joint;

		joint.id_x = 2 * (i + 1) - 1;
		joint.id_y = 2 * (i + 1);
		joint.pos_x = 1500;
		joint.pos_y = 1500;
		snake_ptr->snake_joint.push_back(joint);

		sprintf(snake_ptr->usb_str, "{#%03dP1500T2000!#%03dP1500T2000!}", snake_ptr->snake_joint.at(i).id_x, snake_ptr->snake_joint.at(i).id_y);
		serialPrintf(ser, snake_ptr->usb_str);
	}
}

#endif // !SNAKE_INIT_H