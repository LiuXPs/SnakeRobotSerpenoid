########################################################################################################################

# This file is part of SnakeRobotSerpenoid
#
# Copyright (C) 2018-2024 Xupeng Liu.
#
# SnakeRobotSerpenoid is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
# SnakeRobotRaspberryPiPython is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with SnakeRobotSerpenoid.
# If not, see <http://www.gnu.org/licenses/>.

########################################################################################################################


cmake_minimum_required(VERSION 3.22)
project(SnakeRobotSerpenoid)

set(CMAKE_CXX_STANDARD 20)

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

include_directories(include)

set(HEADER_FILES
        snake_body.h
        snake_init.h
        snake_motion_1.h
        snake_motion_3.h
        snake_servo_run.h
        snake_fun_xy.h
        snake_joint.h
        snake_motion_2.h
        snake_motion_4.h
        )

set(SOURCE_FILES
        snake_main.cpp
        )

add_executable(${PROJECT_NAME}
        ${HEADER_FILES}
        ${SOURCE_FILES}
        )

target_link_libraries(${PROJECT_NAME}
        ${WIRINGPI_LIBRARIES}
        )