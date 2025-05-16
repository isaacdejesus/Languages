const hasCycle = (head: ListNode | null): boolean => {
    if(!head)
        false;
    if(head)
    {
        let slow: ListNode | null = head;
        let fast: ListNode | null = head;
        
            while(fast !== null && fast.next !== null)
            {
                slow = slow.next;
                fast = fast.next.next;
                if(slow === fast)
                    return true;
            }
    }
    return false;
}