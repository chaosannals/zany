
def quick_sort_partition(target, start, end):
    '''
    把数组内的数按分界值分成大小两边
    '''
    pivot = target[start] # 取第一个位分界值
    left = start
    right = end
    index = start
    while right >= left:
        # 自左向右排，把小值放到左边
        while right >= left:
            if target[right] < pivot:
                target[left] = target[right]
                index = right
                left += 1
                break
            right -= 1
        # 自右向左排，把大值放到右边
        while right >= left:
            if target[left] > pivot:
                target[right] = target[left]
                index = left
                right -= 1
                break
            left += 1
    target[index] = pivot
    return index

def quick_sort_reduce(target, start, end):
    '''
    快速排序，递归对每一段进行分组
    '''
    if start >= end:
        return
    slot = quick_sort_partition(target, start, end)
    quick_sort_reduce(target, start, slot - 1)
    quick_sort_reduce(target, slot + 1, end)
    

def quick_sort(source):
    '''
    快速排序：占坑法
    平均时间复杂度：O(nlogn)
    '''
    target = source[:]
    quick_sort_reduce(target, 0, len(target) - 1)
    return target
    
source = [3,2,1,5,8,6,3,9,7,8,9,10,11,12,3,17,13,15]
print(source)
print(quick_sort(source))