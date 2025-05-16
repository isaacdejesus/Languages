class node{
    constructor(value, next = null)
    {
        this.value = value;
        this.next = next;
    }
}

const find_cycle_start = (head) =>
{
    cycle_length = 0;
    let slow = head;
    let fast = head;
    while((fast !== null && fast.next !== null))
    {
        fast = fast.next.next;
        slow = slow.next;
        if(slow === fast)
        {
            cycle_length = calc_cycle_length(slow);
            break;
        }
    }
    return find_start(head, cycle_length);
}

const calc_cycle_length = (slow) => {
    let current = slow;
    let cycle_length = 0;
    while(true)
    {
        current = current.next;
        cycle_length++;
        if(current === slow)
            break;
    }
    return cycle_length;
}

const find_start = (head, cycle_length) => {
    let pointer_1 = head;
    let pointer_2 = head;
    while(cycle_length > 0)
    {
        pointer_2 = pointer_2.next;
        cycle_length--;
    }
    while(pointer_1 !== pointer_2)
    {
        pointer_1 = pointer_1.next;
        pointer_2 = pointer_2.next;
    }
    return pointer_1;
}
const head = new node(1);
head.next = new node(2);
head.next.next = new node(3);
head.next.next.next = new node(4);
head.next.next.next.next = new node(5);
head.next.next.next.next.next = new node(6);
head.next.next.next.next.next.next = head.next.next;
console.log(`list cycle start: ${find_cycle_start(head).value}`);

head.next.next.next.next.next.next = head.next.next.next
console.log(`list cycle start: ${find_cycle_start(head).value}`);

head.next.next.next.next.next.next = head;
console.log(`list cycle start: ${find_cycle_start(head).value}`);
