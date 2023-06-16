#coding=gbk

import random
list = [random.randrange(0,20,1) for i in range (100)]#随机生成原数列
print('原数列:')
print(list)#输出原数列

feng = 0
gu = 0

print("\n波峰有:")
i=0
while i<99:#从头开始直到第99个数遍历
    while list[i]<list[i+1]:#循环寻找递增结尾
        i=i+1
        if i==99:#确保不会越界
            break
    if i!=0 and i != 99:
        print(list[i], end =" ")
        feng=feng+1#输出波峰，并使得波峰数+1
    if i==99:
            break#确保不会越界
    while list[i]>=list[i+1]:#从波峰开始寻找其后递减或相等的所有项的末尾
        i=i+1
        if i==99:#确保不会越界
            break
print('\n波峰共',feng,'个\n')#输出个数

print("\n波谷有:")
i=0
while i<99:#从头开始直到第99个数遍历
    while list[i]>list[i+1]:#循环寻找递减项结尾
        i=i+1
        if i==99:#确保不会越界
            break
    if i!=0 and i != 99:#输出波谷，并使得波谷数+1
        print(list[i], end =" ")
        gu=gu+1
    if i==99:
            break#确保不会越界
    while list[i]<=list[i+1]:#从波谷开始寻找其后递增或相等的所有项的末尾
        i=i+1
        if i==99:#确保不会越界
            break
print('\n波谷共',gu,'个\n')#输出个数