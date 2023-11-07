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


#ifndef SNAKE_SERVO_RUN_H
#define SNAKE_SERVO_RUN_H

#pragma once
#include "snake_body.h"
#include "snake_fun_xy.h"

void SnakeServoRun(int ser, SnakeBody* SnakePtr, double time, unsigned int interval)
{
	for (int i = 0; i < SnakePtr->snake_n - 1; i++)
	{
		SnakeFunXY(SnakePtr, i, time);
		sprintf(SnakePtr->usb_str, "{#%03dP%04dT%04d!#%03dP%04dT%04d!}",
			SnakePtr->snake_joint.at(i).id_x, SnakePtr->snake_joint.at(i).pos_x, interval,
			SnakePtr->snake_joint.at(i).id_y, SnakePtr->snake_joint.at(i).pos_y, interval);
		serialPrintf(ser, SnakePtr->usb_str);
	}
}

#endif // !SNAKE_SERVO_RUN_H