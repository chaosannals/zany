def insert_sort(raw):
    '''
    插入排序
    '''
    count = len(raw)
    for i in range(1, count):
        v = raw[i]
        index = i # 需要被重写入的位置索引
        for j in range(i - 1, -1, -1):
            if v >= raw[j]:
                break
            raw[j + 1] = raw[j]
            index = j # 往前排
        raw[index] = v
    return raw

raw = [3,2,1,5,8,6,3,9,7,8,9,10,11,12]
print(raw)
print(insert_sort(raw))