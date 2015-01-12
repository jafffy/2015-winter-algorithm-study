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
 
        idx.next = idx.next.next

    def push_back(self, data):
        if self.head == None:
            self.head = Node()
            self.head.data = data
            self.head.next = None
            return

        idx = self.head

        while idx.next != None:
            idx = idx.next

        newNode = Node()
        newNode.data = data
        newNode.next = None
        idx.next = newNode
        
    def print_all(self):         
        idx = self.head

        while idx != None:
            print idx.data
            idx = idx.next

l = List()

for i in range(10):
    l.push_back(i)

l.print_all()

l.pop(l.head)
l.pop(l.head.next.next.next)

l.print_all()
