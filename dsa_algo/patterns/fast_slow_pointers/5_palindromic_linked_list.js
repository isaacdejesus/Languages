class node {
    constructor(value, next = null)
    {
        this.value = value;
        this.next = next;
    }
}

const is_palindromic = (head) =>{
    if(head === null || head.next === null)
        return true;
    let slow = head;
    let fast = head;
    while((fast !== null && fast.next !== null))
    {
        slow = slow.next;
        fast = fast.next.next;
    }
    head_second_half = reverse(slow);
    cp_head_second_hald = head_second_half;
    while((head !== null && head_second_half !== null))
    {
        if(head.value !== head_second_half.value)
            break;
        head = head.next;
        head_second_half = head_second_half.next;
    }
    reverse(cp_head_second_hald);
    if(head === null || head_second_half === null)
        return true;
    return false;
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

const head = new node(2);
head.next = new node(4);
head.next.next = new node(6);
head.next.next.next = new node(4);
head.next.next.next.next = new node(2);
console.log(`is pal: ${is_palindromic(head)}`);

head.next.next.next.next.next = new node(2);
console.log(`is pal: ${is_palindromic(head)}`);
