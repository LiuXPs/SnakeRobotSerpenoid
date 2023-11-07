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


#ifndef CAL_PHASE_H
#define CAL_PHASE_H

#include "snake_robot.h"

void cal_phase(SnakeRobot* snake_ptr)
{
	switch (snake_ptr->mode)
	{
	case 1:
	case 2:
	case 3:
		snake_ptr->phase_y = 2 * PI * snake_ptr->wave_kn / snake_ptr->joint_n;
		snake_ptr->phase_p = 2 * PI * snake_ptr->wave_kn / snake_ptr->joint_n;
		break;
	case 4:
		snake_ptr->phase_y = 0;
		snake_ptr->phase_p = 0;
		break;
	case 5:
		double kappa = snake_ptr->spiral_r / (pow(snake_ptr->spiral_r, 2) + pow(snake_ptr->spiral_p, 2));
		double tau = snake_ptr->spiral_p / (pow(snake_ptr->spiral_r, 2) + pow(snake_ptr->spiral_p, 2));
		snake_ptr->phase_y = tau * snake_ptr->link_y;
		snake_ptr->phase_p = tau * snake_ptr->link_p;
		break;
	default:
		break;
	}
}

#endif // !CAL_PHASE_H
