# -*- coding: utf-8 -*-
#�������Ľ���
import RPi.GPIO as GPIO#������ݮ��ģ��
import time#����ʱ��ģ��
GPIO.setmode(GPIO.BCM)#ȷ������ģʽΪbcmģʽ
led = 21#��led��Ϊ21������
GPIO.setup(led, GPIO.OUT)#��21����������Ϊ���
print("����ߵ�ƽ")
GPIO.output(led, GPIO.HIGH)#21����������ߵ�ƽ
time.sleep(5)#���5��
GPIO.output(led, GPIO.LOW)#21����������ߵ�ƽ
print("����͵�ƽ")
GPIO.cleanup#�ͷ�ʹ�õ�GPIO����

