from  __future__ import print_function

class node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next;
    def print_list(self):
        temp = self
        while temp is not None:
            print(temp.value, end='')
            temp = temp.next
        print()
def find_cycle_start(head):
    cycle_length = 0
    slow, fast = head, head
    while(fast is not None and fast.next is not None):
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            cycle_length = calc_cycle_length(slow)
            break
    return find_start(head, cycle_length)
def calc_cycle_length(slow):
    current = slow
    cycle_length = 0;
    while True:
        current = current.next
        cycle_length += 1
        if current == slow:
            break
    return cycle_length
def find_start(head, cycle_length):
    pointer_1 = head
    pointer_2 = head
    while cycle_length > 0:
        pointer_2 = pointer_2.next
        cycle_length -= 1
    while pointer_1 != pointer_2:
        pointer_1 = pointer_1.next
        pointer_2 = pointer_2.next
    return pointer_1

def main():
    head = node(1)
    head.next = node(2)
    head.next.next = node(3)
    head.next.next.next = node(4)
    head.next.next.next.next = node(5)
    head.next.next.next.next.next = node(6)

    head.next.next.next.next.next.next = head.next.next
    print("list cycle start: " + str(find_cycle_start(head).value))

    head.next.next.next.next.next.next = head.next.next.next
    print("list cycle start: " + str(find_cycle_start(head).value))
    
    head.next.next.next.next.next.next = head
    print("list cycle start: " + str(find_cycle_start(head).value))

main()
