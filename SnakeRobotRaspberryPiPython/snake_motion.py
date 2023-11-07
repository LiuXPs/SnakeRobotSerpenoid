# _*_coding:utf-8 _*_


########################################################################################################################

# This file is part of SnakeRobotSerpenoid
#
# Copyright (C) 2018-2024 Xupeng Liu.
#
# SnakeRobotSerpenoid is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
# SnakeRobotSerpenoid is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with SnakeRobotSerpenoid.
# If not, see <http://www.gnu.org/licenses/>.

########################################################################################################################


import math


def snake_motion1(snake, time_run):
    """
    motion1 is the serpentine locomotion
    :param snake:
    :param time_run:
    """
    snake.optimize_x = 1.0 - math.exp(-snake.lam_x * time_run)
    snake.optimize_y = 0.0

    snake.direction_x = 1
    snake.direction_y = 0


def snake_motion2(snake, time_run):
    """
    motion2 is the side winding movement
    :param snake:
    :param time_run:
    """
    snake.optimize_x = 1.0 - math.exp(-snake.lam_x * time_run)
    snake.optimize_y = 1.0 - math.exp(-snake.lam_y * time_run)

    snake.direction_x = -1
    snake.direction_y = -1


def snake_motion3(snake, time_run):
    """
    motion3 is the rectilinear movement
    :param snake:
    :param time_run:
    """
    snake.optimize_x = 0.0
    snake.optimize_y = 1.0 - math.exp(-snake.lam_y * time_run)

    snake.direction_x = 0
    snake.direction_y = -1


def snake_motion4(snake, time_run, e_x):
    """
    motion4 is the turning movement
    :param snake:
    :param time_run:
    :param e_x:
    """
    snake.snake_E_x = e_x

    snake.optimize_x = 1.0 - math.exp(-snake.lam_x * time_run)
    snake.optimize_y = 0

    snake.direction_x = 1
    snake.direction_y = 0


def snake_motion5(snake, time_run):
    """
    motion5 is the new movement
    :param snake:
    :param time_run:
    """
    snake.optimize_x = 1.0 - math.exp(-snake.lam_x * time_run)
    snake.optimize_y = 1.0 - math.exp(-snake.lam_y * time_run)

    snake.snake_A0_x = 80.0
    snake.snake_A0_y = 30.0

    snake.snake_Kn_x = 1.5 * 1.0
    snake.snake_Kn_y = 2 * snake.snake_Kn_x

    snake.snake_T_x = 20 * 1.0
    snake.snake_T_y = snake.snake_T_x

    snake.direction_x = 1
    snake.direction_y = -1


if __name__ == "__main__":
    pass
