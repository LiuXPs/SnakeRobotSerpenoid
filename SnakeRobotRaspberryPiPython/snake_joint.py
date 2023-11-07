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


class SnakeJoint(object):
    def __init__(self, id_x, id_y):
        self.id_x = id_x  # joint ID x
        self.id_y = id_y  # joint ID y
        self.pos_x = 1500  # joint position x
        self.pos_y = 1500  # joint position y

    def reset(self):
        self.id_x = 0
        self.id_y = 0
        self.pos_x = 1500
        self.pos_y = 1500


if __name__ == "__main__":
    joint = SnakeJoint(1, 2)
    print(joint.id_x)
    print(joint.id_y)
    print(joint.pos_x)
    print(joint.pos_y)
