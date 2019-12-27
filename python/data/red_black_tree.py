class RedBlackNode:
    '''
    红黑树节点
    '''

    def __init__(self, key, color='red', top=None):
        self.color = color
        self.key = key
        self.top = None
        self.left = None
        self.right = None

    def stringify(self, level=0):
        '''
        字符串化。
        '''
        return '([{}] {} {} {}-{})'.format(
            level,
            self.key,
            self.color,
            self.left.stringify(level + 1) if self.left != None else 'L',
            self.right.stringify(level + 1) if self.right != None else 'R',
        )

class RedBlackTree:
    '''
    红黑树
    '''
    def __init__(self):
        self.root = None

    def stringify(self):
        '''
        字符串化。
        '''
        return self.root.stringify()

    def insert(self, key):
        '''
        插入。
        '''
        if self.root == None:
            self.root = RedBlackNode(key, color='black')
        else:
            x = self.root
            y = None
            z = RedBlackNode(key, color='red')
            while x != None:
                y = x
                if key < x.key:
                    x = x.left
                elif key > x.key:
                    x = x.right
                else:
                    return
            if key < y.key:
                y.left = z
            elif key > y.key:
                y.right = z
            else:
                return
            z.top = y
            self.fixup_insert(z)
            
    def fixup_insert(self, z):
        '''
        修正插入。
        '''
        while z.top != None and z.top.color == 'red':
            if z.top == z.top.top.left:
                y = z.top.top.right
                if y != None and y.color == 'red':
                    z.top.color = 'black'
                    y.color = 'black'
                    z.top.top.color = 'red'
                    z = z.top.top
                elif z == z.top.right:
                    z = z.top
                    self.left_rotate(z)
                if z.top != None:
                    z.top.color = 'black'
                    if z.top.top != None:
                        z.top.top.color = 'red'
                        self.right_rotate(z.top.top)
            else:
                y = z.top.top.left
                if y != None and y.color == 'red':
                    z.top.color = 'black'
                    y.color = 'black'
                    z.top.top.color = 'red'
                    z = z.top.top
                elif z == z.top.left:
                    z = z.top
                    self.right_rotate(z)
                if z.top != None:
                    z.top.color = 'black'
                    if z.top.top != None:
                        z.top.top.color = 'red'
                        self.left_rotate(z.top.top)
        self.root.color ='black'

    def left_rotate(self, x):
        '''
        左旋。
        '''
        y = x.right
        x.right = y.left
        if y.left != None:
            y.left.top = x
        y.top = x.top
        if x.top == None:
            self.root = y
        elif x == x.top.left:
            x.top.left = y
        else:
            x.top.right = y
        y.left = x
        x.top = y

    def right_rotate(self, x):
        '''
        右旋。
        '''
        y = x.left
        x.left = y.right
        if y.right != None:
            y.right.top = x
        y.top = x.top
        if x.top == None:
            self.root = y
        elif x == x.top.right:
            x.top.right = y
        else:
            x.top.left =y
        y.right = x
        x.top = y

rbt = RedBlackTree()
rbt.insert(6)
rbt.insert(7)
rbt.insert(8)
rbt.insert(6)
rbt.insert(2)
rbt.insert(3)
rbt.insert(1)
print(rbt.stringify())