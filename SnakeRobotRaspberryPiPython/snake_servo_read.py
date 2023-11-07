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


import time


def snake_servo_read(snake, ser, time_run):
    # for i in range(snake.snake_n - 1):
    for i in range(1):
        ser_str = "{#%03dPRAD!}" % snake.snake_joint[i].id_x
        ser.write(ser_str.encode('utf-8'))
        ser_res = ser.readall().decode('utf-8')
        print(ser_res)

        ser_str = "{#%03dPRAD!}" % snake.snake_joint[i].id_y
        ser.write(ser_str.encode('utf-8'))
        ser_res = ser.readall().decode('utf-8')
        print(ser_res)


if __name__ == "__main__":
    pass
