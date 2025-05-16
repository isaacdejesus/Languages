class node {
    value: number;
    next: node | null;
    constructor(value: number, next: node | null = null)
    {
        this.value = value;
        this.next = next;
    }
}

const find_cycle_length = (head: node | null) =>{
    let slow = head;
    let fast = head;
    while(fast !== null && fast.next !== null)
    {
        fast = fast.next.next;
        if(slow)
            slow = slow.next;
        if(slow === fast)
            return calc_cycle_length(slow);
    }
    return 0;
}
const calc_cycle_length = (slow: node | null) =>
{
    let current = slow;
    let cycle_length = 0;
    while(true)
    {
        if(current)
        {
        current = current.next;
        cycle_length += 1
        if(current === slow)
            break;
        }
    }
    return cycle_length;
}

const head = new node(1);
head.next = new node(2);
head.next.next = new node(3);
head.next.next.next = new node(4);
head.next.next.next.next = new node(5);
head.next.next.next.next.next = new node(6);

head.next.next.next.next.next.next = head.next.next;
console.log(`list cycle length: ${find_cycle_length(head)}`);

head.next.next.next.next.next.next = head.next.next.next;
console.log(`list cycle length: ${find_cycle_length(head)}`);
