class node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next
def has_cycle(head):
    slow, fast = head, head
    while fast is not None and fast.next is not None:
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            return True
    return False

def main():
    head = node(1)
    head.next = node(2)
    head.next.next = node(3)
    head.next.next.next = node(4)
    head.next.next.next.next = node(5)
    head.next.next.next.next.next = node(6)
    print("List has cycle: " + str(has_cycle(head)))

    head.next.next.next.next.next.next = head.next.next
    print("List has cycle: " + str(has_cycle(head)))

    head.next.next.next.next.next.next = head.next.next.next
    print("List has cycle: " + str(has_cycle(head)))

main()

