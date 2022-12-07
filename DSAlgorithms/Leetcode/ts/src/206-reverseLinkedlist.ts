const reverseList = (head: ListNode | null): ListNode | null => {
    let prev: ListNode | null = null;
    let next: ListNode | null = null;
    let current: ListNode | null = head;
    while(current !== null)
    {
        next = current.next;
        current = prev;
        prev = current;
    }
    return prev;
}
