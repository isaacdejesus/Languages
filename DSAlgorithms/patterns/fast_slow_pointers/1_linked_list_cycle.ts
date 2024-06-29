class node {
    value: number;
    next: node | null;
    constructor(value: number, next: node | null = null)
    {
        this.value = value;
        this.next = next;
    }
}

const has_cycle = (head: node | null) =>{
    let slow = head;
    let fast = head;
    while(fast !== null && fast.next !== null)
    {
        fast = fast.next.next;
        if(slow)
            slow = slow.next;
        if(slow === fast)
            return true;
    }
    return false;
}

const head = new node(1);
head.next = new node(2);
head.next.next = new node(3);
head.next.next.next = new node(4);
head.next.next.next.next = new node(5);
head.next.next.next.next.next = new node(6);
console.log(`list has cycle: ${has_cycle(head)}`);

head.next.next.next.next.next.next = head.next.next;
console.log(`list has cycle: ${has_cycle(head)}`);

head.next.next.next.next.next.next = head.next.next.next;
console.log(`list has cycle: ${has_cycle(head)}`);
