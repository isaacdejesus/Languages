/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

const reverseKGroup = (head: ListNode | null, k: number): ListNode | null =>{
    const dummy: ListNode = new ListNode();
    dummy.next = head;
    let prev: ListNode = dummy;
    let current: ListNode = dummy.next;
    let temp:ListNode = null;
    let count = k;
    while(current !== null)
    {
        if(count > 1)
        {
            temp = prev.next;
            prev.next = current.next;
            current.next = current.next.next;
            prev.next.next = temp;
            count--;
        }
        else
        {
            prev = current;
            current = current.next;
            count = k
            let end: ListNode = current;
            for(let i = 0; i < k; i++)
            {
                if(end === null)
                    return dummy.next;
                end = end.next;
            }
        }
    }
    return dummy.next;
};