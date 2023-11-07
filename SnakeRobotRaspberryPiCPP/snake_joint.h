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

#pragma once

//一个正交关节
class SnakeJoint
{
public:
	int id_x; //偏航舵机编号
	int id_y; //俯仰舵机编号

	int pos_x; //偏航舵机位置
	int pos_y; //俯仰舵机位置

	void Reset(); //关节重置函数

	SnakeJoint(); //构造函数
	SnakeJoint(const SnakeJoint& joint); //复制构造函数

	~SnakeJoint(); //析构函数

private:

};

void SnakeJoint::Reset()
{
	id_x = 0;
	id_y = 0;
	pos_x = 1500; //位置居中
	pos_y = 1500; //位置居中
}

SnakeJoint::SnakeJoint()
{
	id_x = 0;
	id_y = 0;
	pos_x = 1500;
	pos_y = 1500;
}

SnakeJoint::SnakeJoint(const SnakeJoint& snakejoint)
{
	id_x = snakejoint.id_x;
	id_y = snakejoint.id_y;
	pos_x = snakejoint.pos_x;
	pos_y = snakejoint.pos_y;
}

SnakeJoint::~SnakeJoint()
{
}

#endif // !SNAKE_JOINT_H