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


import snake_joint


class SnakeBody(object):
    def __init__(self, snake_n):
        self.snake_joint = [SnakeJoint.SnakeJoint(0, 0) for i in range(snake_n - 1)]

        # the control parameters of waveform propagation direction in horizontal and vertical directions
        self.direction_x = 0
        self.direction_y = 0

        # the parameters of optimize function
        self.lam_x = 0
        self.lam_y = 0
        self.optimize_x = 0
        self.optimize_y = 0

        # the parameters of serpenoid curve in the horizontal rotary direction
        self.snake_A0_x = 0
        self.snake_Kn_x = 0  # the wave number
        self.snake_E_x = 0  # the bias of the serpenoid curve curvature
        self.snake_L_x = 0  # the half length of the links
        self.snake_T_x = 0  # the time of per waveform

        # the parameters in the horizontal rotary direction
        self.amplitude_x = 0  # the amplitude of joint angle
        self.frequency_x = 0  # the joint angular frequency
        self.phase_x = 0  # the phase difference between the joint angles
        self.phi_x = 0  # joint angle offset

        # the parameters of serpenoid curve in the vertical rotary direction
        self.snake_A0_y = 0
        self.snake_Kn_y = 0  # the wave number
        self.snake_E_y = 0  # the bias of the serpenoid curve curvature
        self.snake_L_y = 0  # the half length of the links
        self.snake_T_y = 0  # the time of per waveform

        # the parameters in the vertical rotary direction
        self.amplitude_y = 0  # the amplitude of joint angle
        self.frequency_y = 0  # the joint angular frequency
        self.phase_y = 0  # the phase difference between the joint angles
        self.phi_y = 0  # joint angle offset

        self.usb_str = ""  # the instruction of steer servo
        self.mode = 0  # movement patterns
        self.snake_n = snake_n  # the number of links of snake like robot


if __name__ == "__main__":
    body = SnakeBody(11)
    print(body.snake_joint[0].id_x)
    print(body.snake_joint[0].id_y)
