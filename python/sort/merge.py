import math


def merge_sort_merge(target, start, middle, end):
    '''
    '''
    buffer = [0]*(end - start + 1)
    left = start
    right = middle + 1
    index = 0
    # 把左右排序写入缓存
    while left <= middle and right <= end:
        if target[left] <= target[right]:
            buffer[index] = target[left]
            index += 1
            left += 1
        else:
            buffer[index] = target[right]
            index += 1
            right += 1
    # 把左边剩余的写入
    while left <= middle:
        buffer[index] = target[left]
        index += 1
        left += 1
    # 把右边剩余的写入
    while right <= end:
        buffer[index] = target[right]
        index += 1
        right += 1
    for i in range(0, len(buffer)):
        target[start + i] = buffer[i]


def merge_sort_reduce(target, start, end):
    '''
    '''
    if start < end:
        middle = math.floor((start + end) / 2)
        merge_sort_reduce(target, start, middle)
        merge_sort_reduce(target, middle + 1, end)
        merge_sort_merge(target, start, middle, end)


def merge_sort(source):
    '''
    归并排序
    平均时间复杂度：O(nlogn)
    '''
    target = source[:]
    merge_sort_reduce(target, 0, len(target) - 1)
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3, 17, 13, 15]
print(source)
print(merge_sort(source))
