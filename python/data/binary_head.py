import math

class MinBinaryHead:
    '''
    '''

    def __init__(self, data=None):
        '''
        '''
        self.data = data if None != data else []
        count = len(self.data)
        for i in range(math.ceil(count / 2), -1, -1):
            self.adjust_down(i, count - 1)
    
    def insert(self, item):
        '''
        '''
        self.data.append(item)
        self.adjust_up()

    def adjust_up(self):
        '''
        '''
        target = len(self.data) - 1
        parent = math.floor((target - 1) / 2)
        tmp = self.data[target]
        while target > 0 and tmp < self.data[parent]:
            self.data[target] = self.data[parent]
            target = parent
            parent = math.floor((target - 1) / 2)
        self.data[target] = tmp

    def adjust_down(self, parent, lenght):
        '''
        '''
        tmp = self.data[parent]
        target = 2 * parent + 1
        while target < lenght:
            n = target + 1 
            if n < lenght and self.data[n] < self.data[target]:
                target += 1
            if tmp < self.data[target]:
                break
            self.data[parent] = self.data[target]
            parent = target
            target = 2 * parent + 1
        self.data[parent] = tmp

source = [3, 2, 1, 5, 8, 6, 3, 9, 7, 8, 9, 10, 11, 12, 3, 17, 13, 15]
print(source)
bh = MinBinaryHead(source)
print(bh.data)
bh.insert(6)
print(bh.data)
