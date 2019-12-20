'''
插入排序及其变种希尔排序
'''
import math


def insert_sort(source):
    '''
    插入排序
    平均时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    for i in range(1, count):
        tmp = target[i]
        index = i  # 需要被重写入的位置索引
        for j in range(i - 1, -1, -1):
            if tmp >= target[j]:
                break
            target[j + 1] = target[j]
            index = j  # 往前排
        target[index] = tmp
    return target


def shell_sort(source):
    '''
    希尔排序
    【不稳定排序】
    平均时间复杂度：O(nlogn)
    最坏时间复杂度：O(n^2)
    '''
    target = source[:]
    count = len(target)
    d = count
    while d > 1:
        d = math.ceil(d / 2)
        for i in range(0, d):  # 遍历步进增量为d的每一组
            for j in range(i + d, count, d):  # 步进位 d 的插入排序
                tmp = target[j]
                index = j
                for k in range(j - d, -1, -d):
                    if tmp >= target[k]:
                        break
                    target[k + d] = target[k]
                    index = k
                target[index] = tmp
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3, 17, 13, 15]
print(source)
print(insert_sort(source))
print(shell_sort(source))
