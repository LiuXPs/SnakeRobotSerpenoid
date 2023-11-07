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


#ifndef SNAKE_MOTION_4_H
#define SNAKE_MOTION_4_H

#pragma once
#include "snake_body.h"

void SnakeMotion4(SnakeBody* snake_ptr, double time, double e_x)
{
	snake_ptr->snake_E_x = e_x;
	snake_ptr->phi_x = 2 * snake_ptr->snake_E_x * snake_ptr->snake_L_x;

	snake_ptr->optimize_x = 1.0 - exp(-snake_ptr->lamda_x * time);
	snake_ptr->optimize_y = 0;

	snake_ptr->direction_x = 1;
	snake_ptr->direction_y = 0;
}

#endif // !SNAKE_MOTION_4_H