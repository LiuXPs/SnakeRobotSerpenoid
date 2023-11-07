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


#ifndef CAL_POSITION_H
#define CAL_POSITION_H

#include "snake_robot.h"

void cal_position(SnakeRobot* snake_ptr) {
	for (int i = 0; i < snake_ptr->joint_n - 1; i++)
	{
		//�ؽڽǶ�ת��Ϊ�������λ��
		snake_ptr->snake_joints[i].pos_y = int(snake_ptr->optimize_y * (snake_ptr->amplitude_y * sin(snake_ptr->omega_y * snake_ptr->time_run + snake_ptr->direction_y * (snake_ptr->joint_n - i) * snake_ptr->phase_y) + snake_ptr->fai_y) * 1000 / 135 + 1500 + 0.5);
		snake_ptr->snake_joints[i].pos_p = int(snake_ptr->optimize_p * (snake_ptr->amplitude_p * sin(snake_ptr->omega_p * snake_ptr->time_run + snake_ptr->direction_p * (snake_ptr->joint_n - i) * snake_ptr->phase_p + PI / 2) + snake_ptr->fai_p) * 1000 / 135 + 1500 + 0.5);
	}
}

#endif // !CAL_POSITION_H
