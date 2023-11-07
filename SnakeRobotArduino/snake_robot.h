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


#ifndef SNAKE_ROBOT_H
#define SNAKE_ROBOT_H

#include "snake_joint.h"

//机器人定义
class SnakeRobot
{
public:
	SnakeRobot(); //构造函数
	~SnakeRobot(); //析构函数

	void reset(); //机器人重置函数

public:
	//关节
	SnakeJoint snake_joints[10]; //正交关节数量

	//时间参数
	long time_start; //起始时间 ms
	long time_current; //当前时间 ms
	int time_interval; //运动离散时间间隔 ms
	double time_run; //运行时间 s

	//优化函数参数
	double lamda_y; //偏航关节优化系数
	double lamda_p; //俯仰关节优化系数
	double optimize_y; //偏航关节优化函数
	double optimize_p; //俯仰关节优化函数

	//运动步态参数
	int mode; //运动模式: 1:蜿蜒运动 2:行波运动 3:侧移运动 4:弧形滚动 5:螺旋攀爬
	int joint_n; //蛇形机器人连杆数量，正交关节数量

	double link_y; //偏航关节连杆长度的一半
	double link_p; //俯仰关节连杆长度的一半

	double amplitude_y; //偏航关节幅值，度
	double amplitude_p; //俯仰关节幅值，度
	double fai_y; //偏置角，度
	double fai_p; //偏置角，度
	double omega_y; //偏航关节频率，弧度
	double omega_p; //俯仰关节频率，弧度
	double phase_y; //偏航关节相位，弧度
	double phase_p; //俯仰关节相位，弧度

	int direction_y; //偏航关节方向
	int direction_p; //控制方向

	double wave_kn; //波形个数
	double wave_a0_y; //偏航波形初始角，度
	double wave_a0_p; //俯仰波形初始角，度

	double cshape_r; //弧形半径，米

	double spiral_r; //螺旋半径，米
	double spiral_p; //螺距长度，米

	//通信参数
	char cmd_return[40] = ""; //15*2+10;
	//char cmd_return[310] = ""; //15*舵机数目+10;

private:

};

SnakeRobot::SnakeRobot()
{
	reset();
}

SnakeRobot::~SnakeRobot()
{
}

void SnakeRobot::reset()
{
	for (int i = 0; i < (joint_n - 1); i++)
	{
		snake_joints[i].reset();
	}

	time_start = 0;
	time_current = 0;
	time_interval = 100;
	time_run = 0;

	lamda_y = 0.5;
	lamda_p = 0.5;
	optimize_y = 0;
	optimize_p = 0;

	mode = 1;
	joint_n = 10;

	link_y = 0.1;
	link_p = 0.1;

	amplitude_y = 0;
	amplitude_p = 0;
	omega_y = PI / 3;
	omega_p = PI / 3;
	phase_y = 0;
	phase_p = 0;
	fai_y = 0;
	fai_p = 0;

	direction_y = 1;
	direction_p = -1;

	wave_kn = 1;
	wave_a0_y = 50;
	wave_a0_p = 10;

	cshape_r = 1;

	spiral_r = 0.5;
	spiral_p = 0.2;
}

#endif // !SNAKE_ROBOT_H