class node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next
def find_cycle_length(head):
    slow, fast = head, head
    while fast is not None and fast.next is not None:
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            return calc_cycle_length(slow)
    return 0
def calc_cycle_length(slow):
    current = slow
    cycle_length = 0;
    while True:
        current = current.next
        cycle_length += 1
        if current == slow:
            break
    return cycle_length

def main():
    head = node(1)
    head.next = node(2)
    head.next.next = node(3)
    head.next.next.next = node(4)
    head.next.next.next.next = node(5)
    head.next.next.next.next.next = node(6)

    head.next.next.next.next.next.next = head.next.next
    print("List cycle length: " + str(find_cycle_length(head)))

    head.next.next.next.next.next.next = head.next.next.next
    print("List cycle length: " + str(find_cycle_length(head)))

main()

