class node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next
def find_mid(head):
    slow = head
    fast = head
    while(fast is not None and fast.next is not None):
        slow = slow.next
        fast = fast.next.next
    return slow

def main():
    head = node(1)
    head.next = node(2)
    head.next.next = node(3)
    head.next.next.next = node(4)
    head.next.next.next.next= node(5)
    print("middle node: " +  str(find_mid(head).value))

    head.next.next.next.next.next = node(6)
    print("middle node: " +  str(find_mid(head).value))
    
    head.next.next.next.next.next.next = node(7)
    print("middle node: " + str(find_mid(head).value))

main()
