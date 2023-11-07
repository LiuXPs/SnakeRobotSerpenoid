[TOC]

------

# SnakeRobotSerpenoid

## SnakeRobotArduino

<p align="left">
	<a href="https://www.arduino.cc/en/software"><img src="https://img.shields.io/badge/Arduino-Org-green?style=flat&logo=arduino"></a>
</p>
针对Arduino的版本

## SnakeRobotRaspberryPiCPP

<p align="left">
	<a href="https://www.raspberrypi.com/"><img src="https://img.shields.io/badge/RaspberryPi-Org-ff69b4?style=flat&logo=raspberrypi"></a>
</p>
针对树莓派的C++版本

## SnakeRobotRaspberryPiPython

<p align="left">
	<a href="https://www.raspberrypi.com/"><img src="https://img.shields.io/badge/RaspberryPi-Org-ff69b4?style=flat&logo=raspberrypi"></a>
</p>
针对树莓派的Python版本

------

# 安装依赖

## 安装支持64位系统的WiringPi (SnakeRobotRaspberryPiCPP需要安装此库)

<p align="left">
	<a href="https://github.com/WiringPi/WiringPi.git"><img src="https://img.shields.io/static/v1?label=WiringPi&message=GitHub&color=blue&logo=GitHub"></a>
</p>


### 下载WiringPi

```shell
$ wget https://github.com/WiringPi/WiringPi/releases/download/2.61-1/wiringpi-2.61-1-arm64.deb
```

### 安装WiringPi

```shell
$ sudo dpkg -i wiringpi-2.61-1-arm64.deb
```

## 安装GPIO (SnakeRobotRaspberryPiPython需要安装此库)

### 提前安装和配置好树莓派上的Python3环境

### 安装GPIO

```shell
$ sudo apt-get install python3-rpi.gpio
```

------

