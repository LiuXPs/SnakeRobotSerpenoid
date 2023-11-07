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
import time
import snake_body
import snake_init
import snake_motion
import snake_servo_read
import snake_servo_run

global time_start
global time_current
global time_run
global time_interval
global snake
global ser
global e_x

time_start = 0
time_current = 0
time_run = 0
time_interval = 0.1
e_x = 10

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=0.5)

snake = SnakeBody.SnakeBody(11)
SnakeInit.snake_init(snake, ser)
time.sleep(3)

time_start = time.time()
time_current = time.time()

try:
    while ser.isOpen():
        ser.flushInput()

        if (time.time() - time_current) >= time_interval:
            time_current = time.time()
            time_run = time_current - time_start
            # SnakeServoRead.snake_servo_read(snake, ser, time_run)
            if snake.mode == 1:
                SnakeMotion.snake_motion1(snake, time_run)
            elif snake.mode == 2:
                SnakeMotion.snake_motion2(snake, time_run)
            elif snake.mode == 3:
                SnakeMotion.snake_motion3(snake, time_run)
            elif snake.mode == 4:
                SnakeMotion.snake_motion4(snake, time_run, e_x)
            elif snake.mode == 5:
                SnakeMotion.snake_motion5(snake, time_run)
            SnakeServoRun.snake_servo_run(snake, ser, time_run, time_interval)

        ser.flushInput()
except:
    ser.close()

if __name__ == "__main__":
    pass
