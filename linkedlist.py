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
