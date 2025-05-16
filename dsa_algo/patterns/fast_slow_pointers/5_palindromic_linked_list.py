class node:
    def __init__(self, value, next = None):
        self.value = value
        self.next = next

def is_palindromic(head):
    if head is None or head.next is None:
        return True
    slow, fast = head, head
    while(fast is not None and fast.next is not None):
        slow = slow.next
        fast = fast.next.next
    head_second_half = reverse(slow)
    copy_head_second_half = head_second_half
    while(head is not None and head_second_half is not None):
        if head.value != head_second_half.value:
            break
        head = head.next
        head_second_half = head_second_half.next
    reverse(copy_head_second_half)
    if head is None or head_second_half is None:
        return True
    return False
def reverse(head):
    prev = None
    while(head is not None):
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev

def main():
    head = node(2)
    head.next = node(4)
    head.next.next = node(6)
    head.next.next.next = node(4)
    head.next.next.next.next = node(2)
    print("is pal: " + str(is_palindromic(head)))

    head.next.next.next.next.next = node(2)
    print("is pal: " + str(is_palindromic(head)))

main()
