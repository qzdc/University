# -*- coding: utf-8 -*-
#导入中文解码
import RPi.GPIO as GPIO#导入树莓派模块
import time#导入时间模块
GPIO.setmode(GPIO.BCM)#确定引脚模式为bcm模式
led = 21#将led设为21号引脚
GPIO.setup(led, GPIO.OUT)#将21号引脚设置为输出
print("输出高电平")
GPIO.output(led, GPIO.HIGH)#21号引脚输出高电平
time.sleep(5)#间隔5秒
GPIO.output(led, GPIO.LOW)#21号引脚输出高电平
print("输出低电平")
GPIO.cleanup#释放使用的GPIO引脚

