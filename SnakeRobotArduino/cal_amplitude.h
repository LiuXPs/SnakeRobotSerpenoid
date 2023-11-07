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


#ifndef CAL_AMPLITUDE_H
#define CAL_AMPLITUDE_H

#include "snake_robot.h"

void cal_amplitude(SnakeRobot* snake_ptr) {
	switch (snake_ptr->mode)
	{
	case 1:
		snake_ptr->amplitude_y = 2 * snake_ptr->wave_a0_y * sin((snake_ptr->wave_kn * PI) / snake_ptr->joint_n);
		snake_ptr->amplitude_p = 0;
		break;
	case 2:
		snake_ptr->amplitude_y = 0;
		snake_ptr->amplitude_p = 2 * snake_ptr->wave_a0_p * sin((snake_ptr->wave_kn * PI) / snake_ptr->joint_n);
		break;
	case 3:
		snake_ptr->amplitude_y = 2 * snake_ptr->wave_a0_y * sin((snake_ptr->wave_kn * PI) / snake_ptr->joint_n);
		snake_ptr->amplitude_p = 2 * snake_ptr->wave_a0_p * sin((snake_ptr->wave_kn * PI) / snake_ptr->joint_n);
		break;
	case 4:
		snake_ptr->amplitude_y = 2 * snake_ptr->link_y / snake_ptr->cshape_r * 180 / PI;
		snake_ptr->amplitude_p = 2 * snake_ptr->link_p / snake_ptr->cshape_r * 180 / PI;
		break;
	case 5:
		double kappa = snake_ptr->spiral_r / (pow(snake_ptr->spiral_r, 2) + pow(snake_ptr->spiral_p, 2));
		double tau = snake_ptr->spiral_p / (pow(snake_ptr->spiral_r, 2) + pow(snake_ptr->spiral_p, 2));
		snake_ptr->amplitude_y = 2 * kappa / tau * sin(tau * snake_ptr->link_y) * 180 / PI;
		snake_ptr->amplitude_p = 2 * kappa / tau * sin(tau * snake_ptr->link_p) * 180 / PI;
		break;
	default:
		break;
	}

}

#endif // !CAL_AMPLITUDE_H
