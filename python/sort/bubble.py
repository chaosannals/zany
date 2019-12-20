'''
冒泡排序及其变种鸡尾酒排序、快速排序
'''
import math


def bubble_sort_2(source):
    '''
    双循环结构冒泡排序
    平均时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    for i in range(0, count):
        for j in range(0, count - i - 1):
            if target[j] > target[j + 1]:
                tmp = target[j]
                target[j] = target[j+1]
                target[j+1] = tmp
    return target


def bubble_sort_1(source):
    '''
    双循环结构带标记冒泡排序
    平均时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    for i in range(0, count):
        final = True
        for j in range(0, count - i - 1):
            if target[j] > target[j + 1]:
                tmp = target[j]
                target[j] = target[j + 1]
                target[j + 1] = tmp
                final = False
        if final:
            break
    return target


def bubble_sort(source):
    '''
    双循环结构带标记带有序锚点冒泡排序
    平均时间复杂度：O(n^2)
    '''
    anchor = 0
    target = source[:]
    count = len(target)
    border = count - 1
    for _ in range(0, count):
        final = True
        for j in range(0, border):
            if target[j] > target[j + 1]:
                tmp = target[j]
                target[j] = target[j + 1]
                target[j + 1] = tmp
                final = False
                anchor = j
        border = anchor
        if final:
            break
    return target


def cocktail_sort_1(source):
    '''
    鸡尾酒排序：合并两次遍历为一次正反两向遍历的冒泡排序
    平均时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    for i in range(0, math.ceil(count / 2)):
        # 正向遍历排序
        final = True
        for j in range(i, count - i - 1):
            if target[j] > target[j + 1]:
                tmp = target[j]
                target[j] = target[j + 1]
                target[j + 1] = tmp
                final = False
        if final:
            break
        # 反向遍历排序
        final = True
        for j in range(count - i - 1, i, -1):
            if target[j] < target[j - 1]:
                tmp = target[j]
                target[j] = target[j - 1]
                target[j - 1] = tmp
                final = False
        if final:
            break
    return target


def cocktail_sort(source):
    '''
    带左右有序边界的鸡尾酒排序
    平均时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    leftIndex = 0
    leftBorder = 0
    rightIndex = 0
    rightBorder = count - 1
    for _ in range(0, math.ceil(count / 2)):
        # 正向排序
        final = True
        for j in range(leftBorder, rightBorder):
            if target[j] > target[j + 1]:
                tmp = target[j]
                target[j] = target[j + 1]
                target[j + 1] = tmp
                final = False
                rightIndex = j
        rightBorder = rightIndex
        if final:
            break
        # 反向排序
        final = True
        for j in range(rightBorder, leftBorder, -1):
            if target[j] < target[j - 1]:
                tmp = target[j]
                target[j] = target[j - 1]
                target[j - 1] = tmp
                final = False
                leftIndex = j
        leftBorder = leftIndex
        if final:
            break
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3]
print(source)
print(bubble_sort_2(source))
print(bubble_sort_1(source))
print(bubble_sort(source))
print(cocktail_sort_1(source))
print(cocktail_sort(source))
