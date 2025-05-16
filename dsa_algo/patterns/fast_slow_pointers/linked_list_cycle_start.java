class list_node {
    int value = 0;
    list_node next;
    list_node(int value)
    {
        this.value = value;
    }
}

class linked_list_cycle_start {
    public static list_node find_cycle_start(list_node head)
    {
        int cycle_length = 0;
        list_node slow = head;
        list_node fast = head;
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if(slow == fast)
            {
                cycle_length = calc_cycle_lenth(slow);
                break;
            }
        }
        return find_start(head, cycle_length);
    }
    private static int calc_cycle_lenth(list_node slow)
    {
        list_node current = slow;
        int cycle_length = 0;
        do{
            current = current.next;
            cycle_length++;
        }
        while(current != slow);
        return cycle_length;
    }
    private static list_node find_start(list_node head, int cycle_length)
    {
        list_node pointer_1 = head;
        list_node pointer_2 = head;
        while(cycle_length > 0)
        {
            pointer_2 = pointer_2.next;
            cycle_length--;
        }
        while(pointer_1 != pointer_2)
        {
            pointer_1 = pointer_1.next;
            pointer_2 = pointer_2.next;
        }
        return pointer_1;
    }
    public static void main(String[] args)
    {
        list_node head = new list_node(1);
        head.next = new list_node(2);
        head.next.next = new list_node(3);
        head.next.next.next = new list_node(4);
        head.next.next.next.next = new list_node(5);
        head.next.next.next.next.next = new list_node(6);
        head.next.next.next.next.next.next = head.next.next;
        System.out.println("list cycle start: " + linked_list_cycle_start.find_cycle_start(head).value);

        head.next.next.next.next.next.next = head.next.next.next;
        System.out.println("list cycle start: " + linked_list_cycle_start.find_cycle_start(head).value);

        head.next.next.next.next.next.next = head;
        System.out.println("list cycle start: " + linked_list_cycle_start.find_cycle_start(head).value);
    }
}
