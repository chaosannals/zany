def count_sort_1(source):
    '''
    '''
    count = len(source)

    # 找出最大值
    m = source[0]
    for i in range(1, count):
        if source[i] > m:
            m = source[i]

    # 创建缓存，开始计数
    buffer = [0]*(m + 1)
    for i in range(0, count):
        buffer[source[i]] += 1

    # 把数回填
    target = [0]*count
    index = 0
    for i in range(0, len(buffer)):
        for _ in range(0, buffer[i]):
            target[index] = i
            index += 1
    return target


def count_sort(source):
    '''
    计数排序
    平均时间复杂度：O(N+M)
    '''
    # 找出最大最小值
    mx = source[0]
    mi = source[0]
    count = len(source)
    for i in range(1, count):
        if source[i] > mx:
            mx = source[i]
        if source[i] < mi:
            mi = source[i]

    # 生成计数缓存
    d = mx - mi
    buffer = [0]*(d + 1)
    for i in range(0, count):
        buffer[source[i] - mi] += 1

    # 把序数加到计数上
    index = 0
    for i in range(0, d + 1):
        index += buffer[i]
        buffer[i] = index

    # 生成结果
    target = [0]*count
    for i in range(count-1, -1, -1):
        j = source[i] - mi # 指定的计数序号
        target[buffer[j] - 1] = source[i]
        buffer[j] -= 1
    return target


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3]
print(source)
print(count_sort_1(source))
print(count_sort(source))
