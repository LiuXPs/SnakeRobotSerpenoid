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


#ifndef CAL_OPTIMIZE_H
#define CAL_OPTIMIZE_H

#include "snake_robot.h"

void cal_optimize(SnakeRobot* snake_ptr) {
	snake_ptr->optimize_y = 1.0 - exp(-1.0 * snake_ptr->lamda_y * snake_ptr->time_run);
	snake_ptr->optimize_p = 1.0 - exp(-1.0 * snake_ptr->lamda_p * snake_ptr->time_run);
}

#endif // !CAL_OPTIMIZE_H
