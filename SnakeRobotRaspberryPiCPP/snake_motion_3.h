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


#ifndef SNAKE_MOTION_3_H
#define SNAKE_MOTION_3_H

#pragma once
#include "snake_body.h"

void SnakeMotion3(SnakeBody* snake_ptr, double time)
{
	snake_ptr->optimize_x = 0.0;
	snake_ptr->optimize_y = 1.0 - exp(-snake_ptr->lamda_y * time);
	snake_ptr->direction_x = 0;
	snake_ptr->direction_y = -1;
}

#endif // !SNAKE_MOTION_3_H