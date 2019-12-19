def selection_sort(raw):
    '''
    选中最小置于前的选择排序
    平均时间复杂度：O(n^2)
    '''
    count = len(raw)
    for i in range(0, count - 1):
        minIndex = i
        for j in range(i + 1, count):
            minIndex = minIndex if raw[minIndex] < raw[j] else j
        tmp = raw[i]
        raw[i] = raw[minIndex]
        raw[minIndex] = tmp
    return raw

raw = [3,2,1,5,8,6,3,9,7,8,9,10,11,12,3]
print(raw)
print(selection_sort(raw))