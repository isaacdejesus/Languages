export class node{
    val: any;
    next: node| null;
    constructor(val: any){
        this.val = val;
        this.next = null;
    }
}

export class linked_list{
    head: node | null;
    tail: node | null;
    length: number;
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    add_to_end(val: any){
        let new_node = new node(val);
        if(this.head === null)
        {
            this.head = new_node;
            this.tail = new_node;
        }
        else
        {
            if(this.tail){
                this.tail.next = new_node;
                this.tail = new_node;
            }
        }
        this.length++;
        //return this;
    }
    add_to_head(val: any){
        let new_node = new node(val);
        if(this.head === null)
        {
            this.head = new_node;
            this.tail = new_node;
        }
        else
        {
            new_node.next = this.head;
            this.head = new_node;
        }
        this.length++;
    }
    //return array containing value of list
    list_values(head: null | node){
        const values = [];
        let current = head;
        while(current != null)
        {
            values.push(current.val);
            current = current.next;
        }
        return values;
    }
    //important. Helper function avoids creation of array at each call
    //We add values to single array instead of creating multiple array at each call
    list_values_recursive(head: null | node){
        const values: any = [];
        this.fill_values_recursive(head, values);
        return values;
    }
    //helper function prevents above function from creating multiple arrays
    fill_values_recursive(head: null | node, values: any[])
    {
        if(head === null)
            return;
        values.push(head.val);
        this.fill_values_recursive(head.next, values);
    }
    sum_contents_of_list(head: null | node)
    {
        let sum = 0;
        let current = head;
        while(current !== null)
        {
            sum+= current.val;
            current= current.next;
        }
        return sum;
    }
    sum_contents_of_list_recursive(head: null | node): any
    {
        if(head === null) 
            return 0;
        return head.val + this.sum_contents_of_list_recursive(head.next);
    }
    is_item_in_list(head: null | node, target: any): boolean
    {
        let current = head;
        while(current !== null)
        {
            if(current.val === target)
                return true;
            current= current.next;
        }
        return false;
    }
    is_item_in_list_recursive(head: null | node, target: any): boolean
    {
        if(head === null)
            return false;

        if(head.val === target)
            return true;
        return this.is_item_in_list_recursive(head.next, target);
    }
    item_at_index_recursive(head: null | node, index: number): any
    {
        if(head === null)
            return null;
        if(index === 0)
            return head.val;
        this.item_at_index_recursive(head.next, index -1);
    }
    item_at_index(head: null | node, index: number): any
    {
        let current = head;
        let count = 0;
        while(current !== null)
        {
            if(count === index)
                return current.val;
            count++;
            current = current.next;
        }
    }
    reverse_list(head: null | node)
    {
        let prev = null;
        let current = head;
        while(current != null)
        {
            const next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    reverse_list_recursive(head: null | node, prev:null | node =  null): null | node
    {
        if(head === null)
            return prev;
        const next = head.next;
        head.next = prev;
        return this.reverse_list_recursive(next, head);
    }
    display() {
        let current = this.head;
        while(current != null)
        {
            console.log(current.val)
            current = current.next;
        }
    }
    display_recursive(head: null | node){
        if(head === null)
            return;
        console.log(head.val);
        this.display_recursive(head.next);
    }
    get_head(){
        return this.head;
    }

}