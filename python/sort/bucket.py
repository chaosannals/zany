import math


def bucket_sort(source):
    '''
    桶排序
    平均时间复杂度：O（n + m + n(logn - logm))
    '''
    # 取最大最小值
    mi = source[0]
    mx = source[0]
    count = len(source)
    for i in range(1, count):
        if source[i] > mx:
            mx = source[i]
        if source[i] < mi:
            mi = source[i]

    # 生成桶
    d = mx - mi
    bucketCount = count # 桶数量
    buckets = [[]]*bucketCount
    for i in range(0, bucketCount):
        buckets[i] = []

    # 把元素分到各个桶里
    for i in range(0, count):
        n = math.floor((source[i] - mi) * (bucketCount - 1) / d)
        buckets[n].append(source[i])

    # 每个桶做排序
    for i in range(0, bucketCount):
        buckets[i].sort()

    # 把排序好的数据填入
    index = 0
    target = [0]*count
    for bucket in buckets:
        for item in bucket:
            target[index] = item
            index += 1
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3]
print(source)
print(bucket_sort(source))
