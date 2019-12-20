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


source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3]
print(source)
print(count_sort_1(source))
