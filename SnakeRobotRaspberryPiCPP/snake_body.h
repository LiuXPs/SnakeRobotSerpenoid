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


#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H

#pragma once
#include <iostream>
#include <vector>
#include "snake_joint.h"

//机器人定义
class SnakeBody
{
public:
	//joint
	std::vector<SnakeJoint> snake_joint; //正交关节数量

	// direction
	int direction_x;
	int direction_y;

	//优化函数
	double lamda_x; //水平方向优化系数
	double lamda_y; //竖直方向优化系数
	double optimize_x; //水平方向优化函数
	double optimize_y; //竖直方向优化函数

	//运动函数参数
	double snake_A0_x; //S波初始角
	double snake_Kn_x; //S波个数
	double snake_E_x; //曲率偏置量
	double snake_L_x; //连杆长度的一半
	double snake_T_x; //传播snakeKn_x个S波的时间

	double amplitude_x; //水平方向幅值
	double frequency_x; //水平方向角频率
	double phase_x; //水平方向相位
	double phi_x; //偏置角

	double snake_A0_y; //S波初始角
	double snake_Kn_y; //S波个数
	double snake_E_y; //曲率偏置量
	double snake_L_y; //连杆长度的一半
	double snake_T_y; //传播snakeKn_x个S波的时间

	double amplitude_y; //竖直方向幅值
	double frequency_y; //竖直方向角频率
	double phase_y; //竖直方向相位
	double phi_y; //偏置角

	//std::string usb_str = ""; //15*2+10;
	char usb_str[40] = ""; //15*2+10;
	//char usb_str[310] = ""; //15*舵机数目+10;

	/*
	运动模式:
	1:蜿蜒运动
	2:侧向运动
	3:行波运动
	4:转弯运动
	*/
	int mode;

	int snake_n; //蛇形机器人连杆数量

	void Reset(); //机器人重置函数

	SnakeBody(int N); //构造函数

	~SnakeBody(); //析构函数

private:

};

void SnakeBody::Reset()
{
	for (int i = 0; i < 10; i++)
	{
		snake_joint.at(i).Reset();
	}

	direction_x = 0;
	direction_y = 0;

	lamda_x = 0.5;
	lamda_y = 0.5;
	optimize_x = 0.0;
	optimize_y = 0.0;

	snake_A0_x = 0.0;
	snake_Kn_x = 1.0;
	snake_E_x = 0.0;
	snake_L_x = 1.0;
	snake_T_x = 10.0;

	amplitude_x = 0.0;
	frequency_x = 0.0;
	phase_x = 0.0;
	phi_x = 0.0;

	snake_A0_y = 0.0;
	snake_Kn_y = 1.0;
	snake_E_y = 0.0;
	snake_L_y = 1.0;
	snake_T_y = 10.0;

	amplitude_y = 0.0;
	frequency_y = 0.0;
	phase_y = 0.0;
	phi_y = 0.0;

	mode = 0;

	snake_n = 0;
}

SnakeBody::SnakeBody(int N)
{
	snake_joint.clear();
	direction_x = 0;
	direction_y = 0;

	lamda_x = 0.5;
	lamda_y = 0.5;
	optimize_x = 0.0;
	optimize_y = 0.0;

	snake_A0_x = 0.0;
	snake_Kn_x = 1.0;
	snake_E_x = 0.0;
	snake_L_x = 1.0;
	snake_T_x = 10.0;

	amplitude_x = 0.0;
	frequency_x = 0.0;
	phase_x = 0.0;
	phi_x = 0.0;

	snake_A0_y = 0.0;
	snake_Kn_y = 1.0;
	snake_E_y = 0.0;
	snake_L_y = 1.0;
	snake_T_y = 10.0;

	amplitude_y = 0.0;
	frequency_y = 0.0;
	phase_y = 0.0;
	phi_y = 0.0;

	mode = 0;

	snake_n = N;
}

SnakeBody::~SnakeBody()
{
}

#endif // !SNAKE_BODY_H