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


def snake_fun_xy(snake, i, time_run):
    """
    calculate joint angle in horizontal and vertical directions
    :param snake:
    :param i:
    :param time_run:
    """
    snake.amplitude_x = -2 * snake.snake_A0_x * math.sin(snake.snake_Kn_x * math.pi / snake.snake_n)
    snake.frequency_x = 2 * snake.snake_Kn_x * math.pi / snake.snake_T_x
    snake.phase_x = 2 * snake.snake_Kn_x * math.pi / snake.snake_n
    snake.phi_x = 2 * snake.snake_E_x * snake.snake_L_x

    snake.amplitude_y = -2 * snake.snake_A0_y * math.sin(snake.snake_Kn_y * math.pi / snake.snake_n)
    snake.frequency_y = 2 * snake.snake_Kn_y * math.pi / snake.snake_T_y
    snake.phase_y = 2 * snake.snake_Kn_y * math.pi / snake.snake_n
    snake.phi_y = 2 * snake.snake_E_y * snake.snake_L_y

    snake.snake_joint[i].pos_x = int(snake.optimize_x * (snake.amplitude_x * math.sin(
        snake.frequency_x * time_run + snake.direction_x * (
                snake.snake_n - i) * snake.phase_x) + snake.phi_x) * 1000 / 135 + 1500 + 0.5)
    snake.snake_joint[i].pos_y = int(snake.optimize_y * (snake.amplitude_y * math.sin(
        snake.frequency_y * time_run + snake.direction_y * (
                snake.snake_n - i) * snake.phase_y + math.pi) + snake.phi_y) * 1000 / 135 + 1500 + 0.5)
