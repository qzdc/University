#coding=gbk

import random
list = [random.randrange(0,20,1) for i in range (100)]#�������ԭ����
print('ԭ����:')
print(list)#���ԭ����

feng = 0
gu = 0

print("\n������:")
i=0
while i<99:#��ͷ��ʼֱ����99��������
    while list[i]<list[i+1]:#ѭ��Ѱ�ҵ�����β
        i=i+1
        if i==99:#ȷ������Խ��
            break
    if i!=0 and i != 99:
        print(list[i], end =" ")
        feng=feng+1#������壬��ʹ�ò�����+1
    if i==99:
            break#ȷ������Խ��
    while list[i]>=list[i+1]:#�Ӳ��忪ʼѰ�����ݼ�����ȵ��������ĩβ
        i=i+1
        if i==99:#ȷ������Խ��
            break
print('\n���干',feng,'��\n')#�������

print("\n������:")
i=0
while i<99:#��ͷ��ʼֱ����99��������
    while list[i]>list[i+1]:#ѭ��Ѱ�ҵݼ����β
        i=i+1
        if i==99:#ȷ������Խ��
            break
    if i!=0 and i != 99:#������ȣ���ʹ�ò�����+1
        print(list[i], end =" ")
        gu=gu+1
    if i==99:
            break#ȷ������Խ��
    while list[i]<=list[i+1]:#�Ӳ��ȿ�ʼѰ������������ȵ��������ĩβ
        i=i+1
        if i==99:#ȷ������Խ��
            break
print('\n���ȹ�',gu,'��\n')#�������