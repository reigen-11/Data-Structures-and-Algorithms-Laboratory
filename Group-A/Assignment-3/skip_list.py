import random


class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.bottom = None

    def find(self, target):
        if self.next is not None and self.next.key <= target:
            return self.next.find(target)
        else:
            return self

    def append(self, target):
        q = self.next
        p = Node(target)
        self.next = p
        p.next = q


class Skiplist:
    def __init__(self):
        self.startList = [Node(-1)]

    def search(self, target: int) -> bool:
        p = self.startList[-1]
        while p is not None and p.key < target:
            p = p.find(target)
            if p.key == target:
                return True
            else:
                p = p.bottom
        return False

    def add(self, num: int) -> None:
        p = self.startList[-1]
        s = []
        while p is not None and p.key < num:
            p = p.find(num)
            s.append(p)
            if p.key == num:
                s.pop()
                while p is not None:
                    s.append(p)
                    p = p.bottom
                break
            else:
                p = p.bottom
        b = None
        p = s.pop()
        p.append(num)
        p.next.bottom = b
        b = p.next
        while random.choice([True, False]):
            if len(s) > 0:
                p = s.pop()
                p.append(num)
                p.next.bottom = b
                b = p.next
            else:
                start = Node(-1)
                start.next = Node(num)
                start.bottom = self.startList[-1]
                start.next.bottom = b
                start.next.next = None
                self.startList.append(start)
                b = start.next

    def find_closest(self, target: int) -> int:
        p = self.startList[-1]
        closest = None
        while p is not None:
            if p.next is None or p.next.key > target:
                if closest is None or abs(p.key - target) < abs(closest - target):
                    closest = p.key
                p = p.bottom
            else:
                p = p.next
        return closest


skiplist = Skiplist()

skiplist.add(3)
skiplist.add(6)
skiplist.add(9)
skiplist.add(12)

print(skiplist.search(9))
print(skiplist.search(7))

print(skiplist.find_closest(5))
print(skiplist.find_closest(10))
