from __future__ import print_function

class node:
    def __init__(self, value, next = None):
        self.value = value
        self.next = next
    def print_list(self):
        temp = self
        while temp is not None:
            print(str(temp.value) + " ", end='')
            temp = temp.next
        print()
def reorder(head):
    if head is None or head.next is None:
        return
    slow, fast = head, head
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next
    head_second_half = reverse(slow)
    head_first_half = head
    while head_first_half is not None and head_second_half is not None:
        temp = head_first_half.next
        head_first_half.next = head_second_half
        head_first_half = temp

        temp =  head_second_half.next
        head_second_half.next = head_first_half
        head_second_half = temp
    if head_first_half is not None:
        head_first_half.next = None
def reverse(head):
    prev = None
    while head is not None:
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev

def main():
    head = node(2)
    head.next = node(4)
    head.next.next = node(6)
    head.next.next.next = node(8)
    head.next.next.next.next = node(10)
    head.next.next.next.next.next = node(12)
    reorder(head)
    head.print_list()

main()
