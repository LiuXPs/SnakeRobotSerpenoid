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


import serial
import snake_body
import time


def snake_init(snake, ser):
    # initialize the parameters
    snake.snake_L_x = 0.1059025
    snake.snake_L_y = 0.1059025
    snake.lam_x = 0.25
    snake.lam_y = 0.25

    """
    mode 1: serpentine locomotion
    mode 2: side winding movement
    mode 3: rectilinear movement
    mode 4: turning movement
    """
    snake.mode = 1  # the default motion mode is 1

    snake.snake_A0_x = 40.0
    snake.snake_Kn_x = 2 * 1.0
    snake.snake_T_x = 10 * 1.0
    snake.snake_E_x = 0.0

    snake.snake_A0_y = 10.0
    snake.snake_Kn_y = snake.snake_Kn_x
    snake.snake_T_y = snake.snake_T_x
    snake.snake_E_y = 0.0

    # number the steer servo and initialize position
    for i in range(snake.snake_n - 1):
        snake.snake_joint[i].id_x = 2 * (i + 1) - 1
        snake.snake_joint[i].id_y = 2 * (i + 1)
        snake.snake_joint[i].pos_x = 1500
        snake.snake_joint[i].pos_y = 1500
        ser_str = "{#%03dP%04dT%04d!}" % (i + 1, 1500, 2000)
        ser.write(ser_str.encode('utf-8'))
        time.sleep(0.2)


if __name__ == "__main__":
    snake = SnakeBody.SnakeBody(11)
    ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=0.5)
    if ser.isOpen():
        snake_init(snake, ser)
