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


import snake_fun_xy


def snake_servo_run(snake, ser, time_run, time_interval):
    for i in range(snake.snake_n - 1):
        SnakeFunXY.snake_fun_xy(snake, i, time_run)
        ser_str = "{#%03dP%04dT%04d!#%03dP%04dT%04d!}" % (
            snake.snake_joint[i].id_x, snake.snake_joint[i].pos_x, int(time_interval * 1000),
            snake.snake_joint[i].id_y, snake.snake_joint[i].pos_y, int(time_interval * 1000))
        ser.write(ser_str.encode('utf-8'))


if __name__ == "__main__":
    pass
