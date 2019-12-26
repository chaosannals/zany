class IntHashMap:
    '''
    整数键的哈希表
    '''

    def __init__(self, size=5):
        '''
        '''
        self.size = size
        self.mark = (1 << size) - 1
        self.data = [None]*(1 << size)

    def resize(self, size):
        '''
        '''
        self.size = size
        self.mark = (1 << size) - 1
        buffer = self.data
        self.data = [None]*(1 << size)
        for i in buffer:
            if isinstance(i, list):
                for j in i:
                    self.put(j[0], j[1])
            elif i != None:
                self.put(i[0], i[1])

    def hash(self, key):
        '''
        '''
        return self.mark & key

    def get(self, key):
        '''
        '''
        index = self.hash(key)
        buffer = self.data[index]
        if isinstance(buffer, list):
            for i in buffer:
                if i[0] == key:
                    return i[1]
            return None
        else:
            return buffer[1]

    def put(self, key, value):
        '''
        '''
        index = self.hash(key)
        buffer = self.data[index]
        if None == buffer:
            self.data[index] = (key, value)
        elif isinstance(buffer, list):
            for i in buffer:
                if i[0] == key:
                    i[1] = value
            buffer.push((key, value))
        elif buffer[0] == key:
            buffer[1] = value
        else:
            self.data[index] = [buffer]
            self.data[index].append((key, value))

hm = IntHashMap()
hm.put(3, 'aaaa')
hm.put(12, 'bbbb')
hm.put(35, 'cccc')
print(hm.data)
print(hm.get(3))
print(hm.get(12))
print(hm.get(35))
hm.resize(6)
print(hm.data)
print(hm.get(3))
print(hm.get(12))
print(hm.get(35))