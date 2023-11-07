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


#ifndef SNAKE_JOINT_H
#define SNAKE_JOINT_H

//一个正交关节
class SnakeJoint
{
public:
	SnakeJoint(); //构造函数
	SnakeJoint(const SnakeJoint& snake_joint); //复制构造函数

	~SnakeJoint(); //析构函数

	void reset(); //关节重置函数

public:
	int id_y; //偏航舵机编号
	int id_p; //俯仰舵机编号

	int pos_y; //偏航舵机位置
	int pos_p; //俯仰舵机位置

private:

};

SnakeJoint::SnakeJoint()
{
	id_y = 0;
	id_p = 0;
	pos_y = 1500;
	pos_p = 1500;
}

SnakeJoint::SnakeJoint(const SnakeJoint& snake_joint)
{
	id_y = snake_joint.id_y;
	id_p = snake_joint.id_p;
	pos_y = snake_joint.pos_y;
	pos_p = snake_joint.pos_p;
}

SnakeJoint::~SnakeJoint()
{
}

void SnakeJoint::reset()
{
	id_y = 0;
	id_p = 0;
	pos_y = 1500; //位置居中
	pos_p = 1500; //位置居中
}

#endif // !SNAKE_JOINT_H