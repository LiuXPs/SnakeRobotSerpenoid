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


#ifndef SNAKE_FUN_XY_H
#define SNAKE_FUN_XY_H

#pragma once
#include "snake_body.h"

void SnakeFunXY(SnakeBody* snake_ptr, int& i, double& time)
{
	snake_ptr->amplitude_x = -2 * snake_ptr->snake_A0_x * sin(snake_ptr->snake_Kn_x * M_PI / snake_ptr->snake_n);
	snake_ptr->frequency_x = 2 * snake_ptr->snake_Kn_x * M_PI / snake_ptr->snake_T_x;
	snake_ptr->phase_x = 2 * snake_ptr->snake_Kn_x * M_PI / snake_ptr->snake_n;
	snake_ptr->phi_x = 2 * snake_ptr->snake_E_x * snake_ptr->snake_L_x;

	snake_ptr->amplitude_y = -2 * snake_ptr->snake_A0_y * sin(snake_ptr->snake_Kn_y * M_PI / snake_ptr->snake_n);
	snake_ptr->frequency_y = 2 * snake_ptr->snake_Kn_y * M_PI / snake_ptr->snake_T_y;
	snake_ptr->phase_y = 2 * snake_ptr->snake_Kn_y * M_PI / snake_ptr->snake_n;
	snake_ptr->phi_y = 2 * snake_ptr->snake_E_y * snake_ptr->snake_L_y;

	snake_ptr->snake_joint.at(i).pos_x = int(snake_ptr->optimize_x * (snake_ptr->amplitude_x * sin(snake_ptr->frequency_x * time + snake_ptr->direction_x * (snake_ptr->snake_n - i) * snake_ptr->phase_x) + snake_ptr->phi_x) * 1000 / 135 + 1500 + 0.5);
	snake_ptr->snake_joint.at(i).pos_y = int(snake_ptr->optimize_y * (snake_ptr->amplitude_y * sin(snake_ptr->frequency_y * time + snake_ptr->direction_y * (snake_ptr->snake_n - i) * snake_ptr->phase_y) + snake_ptr->phi_y) * 1000 / 135 + 1500 + 0.5);
}

#endif // !SNAKE_FUN_XY_H
