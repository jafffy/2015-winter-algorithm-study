class Node:
    def __init__(self):
        self.data = 0
        self.next = None

class List:
    def __init__(self):
        self.head = None
        
    def push(self, prev, data):
        if self.head == None:
            self.head = Node()
            self.head.data = data
            self.head.next = None

            return

        idx = self.head

        while idx.next != prev and idx.next != None:
            idx = idx.next

        newNode = Node()
        newNode.data = data;
        newNode.next =  prev.next
        idx.next = newNode

    def pop(self, target):
        if target == self.head:
            self.head = self.head.next
            return

        idx = self.head

        while idx.next != target and idx.next != None:
            idx = idx.next    
        
        idx.next = None

    def push_back(self, data): # Null check가 필요함
        idx = self.head

        while idx.next != None:
            idx = idx.next

        newNode = Node()
        newNode.data = data
        newNode.next = None
        idx.next = newNode
        
    def print_all(self): # Null check가 필요함
        idx = self.head

        while idx.next != None:
            print idx.data
            idx = idx.next

l = List()

for i in range(1, 10):
    l.push_back(i)

l.print_all()
