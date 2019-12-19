def bubble_sort_2(raw):
    '''
    双循环结构冒泡排序
    '''
    count = len(raw)
    for i in range(0, count):
        for j in range(0, count - i -1):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j+1]
                raw[j+1] = tmp
    return raw

def bubble_sort_1(raw):
    '''
    双循环结构带标记冒泡排序
    '''
    count = len(raw)
    for i in range(0, count):
        final = True
        for j in range(0, count - i - 1):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
        if final:
            break
    return raw

def bubble_sort(raw):
    '''
    双循环结构带标记带有序锚点冒泡排序
    '''
    anchor = 0
    count = len(raw)
    border = count - 1
    for _ in range(0, count):
        final = True
        for j in range(0, border):
            if raw[j] > raw[j + 1]:
                tmp = raw[j]
                raw[j] = raw[j + 1]
                raw[j + 1] = tmp
                final = False
                anchor = j
        border = anchor
        if final:
            break
    return raw

raw = [3,2,1,5,8,6,3,9,7,8,9,10,11,12]
print(raw)
print(bubble_sort_2(raw))
print(bubble_sort_1(raw))
print(bubble_sort(raw))
