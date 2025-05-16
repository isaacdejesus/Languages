class node {
    constructor(value, next = null)
    {
        this.value = value;
        this.next = next;
    }

    print_list() {
        temp = this;
        while(temp !== null)
        {
            process.stdout.write(`${temp.value} `);
            temp = temp.next;
        }
        console.log();
    }
}
const reorder = (head) => {
    if(head === null || head.next === null)
        return;
    let slow = head;
    fast = head;
    while(fast !== null && fast.next !== null)
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    head_second_half = reverse(slow);
    head_first_half = head;
    while(head_first_half !== null && head_second_half !== null)
    {
        temp = head_first_half.next;
        head_first_half.next = head_second_half;
        head_first_half = temp;
        temp = head_second_half.next;
        head_second_half.next = head_first_half;
        head_second_half = temp;
    }
    if(head_first_half !== null)
        head_first_half.next = null
}
const reverse = (head) => {
    let prev = null;
    while(head !== null)
    {
        next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

var head = new node(2);
head.next = new node(4);
head.next.next = new node(6);
head.next.next.next = new node(8);
head.next.next.next.next = new node(10);
head.next.next.next.next.next = new node(12);
reorder(head);
head.print_list();
