import math


def heap_sort_down(target, parentIndex, length):
    '''
    堆下降调整
    '''
    tmp = target[parentIndex]
    childIndex = 2 * parentIndex + 1
    while childIndex < length:
        n = childIndex + 1
        if n < length and target[n] > target[childIndex]:
            childIndex += 1
        if tmp >= target[childIndex]:
            break
        target[parentIndex] = target[childIndex]
        parentIndex = childIndex
        childIndex = 2 * parentIndex + 1
    target[parentIndex] = tmp


def heap_sort(source):
    '''
    堆排序
    不稳定排序
    平均时间复杂度：O(nlogn)
    '''
    target = source[:]
    count = len(target)
    # 生成个二叉堆
    for i in range(math.ceil((count - 2) / 2), -1, -1):
        heap_sort_down(target, i, count)
    for i in range(count-1, 0, -1):
        tmp = target[i]
        target[i] = target[0]
        target[0] = tmp
        heap_sort_down(target, 0, i)
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3, 17, 13, 15]
print(source)
print(heap_sort(source))
