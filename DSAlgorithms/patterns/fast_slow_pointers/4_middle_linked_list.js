class node{
    constructor(value, next = null)
    {
        this.value = value;
        this.next = next;
    }
}

const find_mid = (head) =>{
    let slow = head;
    let fast = head;
    while((fast !== null && fast.next !== null))
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}

head = new node(1);
head.next = new node(2);
head.next.next = new node(3);
head.next.next.next = new node(4);
head.next.next.next.next = new node(5);
console.log(`middle node: ${find_mid(head).value}`);

head.next.next.next.next.next = new node(6);
console.log(`middle node: ${find_mid(head).value}`);

head.next.next.next.next.next.next = new node(7);
console.log(`middle node: ${find_mid(head).value}`);

