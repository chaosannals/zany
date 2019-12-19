'''
冒泡排序，鸡尾酒排序
平均时间复杂度：O(n^2)
'''

import math

def bubble_sort_2(raw):
    '''
    双循环结构冒泡排序
    '''
    count = len(raw)
    for i in range(0, count):
        for j in range(0, count - i -1):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j+1]
                raw[j+1] = tmp
    return raw

def bubble_sort_1(raw):
    '''
    双循环结构带标记冒泡排序
    '''
    count = len(raw)
    for i in range(0, count):
        final = True
        for j in range(0, count - i - 1):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
        if final:
            break
    return raw

def bubble_sort(raw):
    '''
    双循环结构带标记带有序锚点冒泡排序
    '''
    anchor = 0
    count = len(raw)
    border = count - 1
    for _ in range(0, count):
        final = True
        for j in range(0, border):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
                anchor = j
        border = anchor
        if final:
            break
    return raw

def cocktail_sort_1(raw):
    '''
    鸡尾酒排序：合并两次遍历为一次正反两向遍历的冒泡排序
    '''
    count = len(raw)
    for i in range(0, math.ceil(count / 2)):
        # 正向遍历排序
        final = True
        for j in range(i, count - i - 1):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
        if final:
            break
        # 反向遍历排序
        final = True
        for j in range(count - i - 1, i, -1):
            if raw[j] < raw[j - 1]:
                tmp = raw[j]
                raw[j] = raw[j - 1]
                raw[j - 1] = tmp
                final = False
        if final:
            break
    return raw

def cocktail_sort(raw):
    '''
    带左右有序边界的鸡尾酒排序
    '''
    count = len(raw)
    leftIndex = 0
    leftBorder = 0
    rightIndex = 0
    rightBorder = count - 1
    for _ in range(0, math.ceil(count / 2)):
        # 正向排序
        final = True
        for j in range(leftBorder, rightBorder):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
                rightIndex = j
        rightBorder = rightIndex
        if final:
            break
        # 反向排序
        final = True
        for j in range(rightBorder, leftBorder, -1):
            if raw[j] < raw[j - 1]:
                tmp = raw[j]
                raw[j] = raw[j - 1]
                raw[j - 1] = tmp
                final = False
                leftIndex = j
        leftBorder = leftIndex
        if final:
            break
    return raw

raw = [3,2,1,5,8,6,3,9,7,8,9,10,11,12,3]
print(raw)
print(bubble_sort_2(raw))
print(bubble_sort_1(raw))
print(bubble_sort(raw))
print(cocktail_sort_1(raw))
print(cocktail_sort(raw))
