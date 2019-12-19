'''
插入排序及其变种希尔排序
'''
import math

def insert_sort(raw):
    '''
    插入排序
    平均时间复杂度：O(n^2)
    '''
    count = len(raw)
    for i in range(1, count):
        tmp = raw[i]
        index = i # 需要被重写入的位置索引
        for j in range(i - 1, -1, -1):
            if tmp >= raw[j]:
                break
            raw[j + 1] = raw[j]
            index = j # 往前排
        raw[index] = tmp
    return raw

def shell_sort_1(raw):
    '''
    希尔排序
    平均时间复杂度：O(nlogn)
    '''
    count = len(raw)
    d = count
    while d > 1:
        d = math.ceil(d / 2)
        for i in range(0, d): # 遍历步进增量为d的每一组
            for j in range(i + d, count, d): # 步进位 d 的插入排序
                tmp = raw[j]
                index = j
                for k in range(index, -1, -d):
                    if tmp >= raw[k]:
                        break
                    raw[k + d] = raw[k]
                    index = k
                raw[index] = tmp
    return raw

raw = [3,2,1,5,8,6,3,9,7,8,9,10,11,12,3,17,13,15]
print(raw)
print(insert_sort(raw))
print(shell_sort_1(raw))