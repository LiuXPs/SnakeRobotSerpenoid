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


#ifndef SERVO_RUN_H
#define SERVO_RUN_H

#include "snake_robot.h"

void servo_run(SnakeRobot* snake_ptr)
{
	for (int i = 0; i < snake_ptr->joint_n; i++)
	{
		sprintf(snake_ptr->cmd_return, "{#%03dP%04dT%04d!#%03dP%04dT%04d!}",
			snake_ptr->snake_joints[i].id_y, snake_ptr->snake_joints[i].pos_y, snake_ptr->time_interval,
			snake_ptr->snake_joints[i].id_p, snake_ptr->snake_joints[i].pos_p, snake_ptr->time_interval);
		if (i >= 0 && i <= 4)
		{
			Serial2.print(snake_ptr->cmd_return);
		}
		else if (i >= 5 && i <= 9)
		{
			Serial3.print(snake_ptr->cmd_return);
		}
		
		char str_c[100];
		sprintf(str_c, "pos[%d]: %d\tpos[%d]: %d", snake_ptr->snake_joints[i].id_y, snake_ptr->snake_joints[i].pos_y, snake_ptr->snake_joints[i].id_p, snake_ptr->snake_joints[i].pos_p);

		Serial.print(str_c);
		Serial.println();
	}
	Serial.println();
}

#endif // !SERVO_RUN_H