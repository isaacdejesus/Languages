class list_node {
    int value = 0;
    list_node next;

    list_node(int value)
    {
        this.value = value;
    }
}

class linked_list_cycle_length {
    public static int find_cycle_length(list_node head)
    {
        list_node slow = head;
        list_node fast = head;
        while(fast != null && fast.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            if(slow == fast)
                return calc_legth(slow);
        }
        return 0;
    }
    private static int calc_legth(list_node slow)
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
     public static void main(String[] args)
     {
         list_node head = new list_node(1);
         head.next = new list_node(2);
         head.next.next = new list_node(3);
         head.next.next.next = new list_node(4);
         head.next.next.next.next = new list_node(5);
         head.next.next.next.next.next = new list_node(6);

         head.next.next.next.next.next.next = head.next.next;
         System.out.println("Linked list cycle length: " + linked_list_cycle_length.find_cycle_length(head));

         head.next.next.next.next.next.next = head.next.next.next;
         System.out.println("Linked list cycle length: " + linked_list_cycle_length.find_cycle_length(head));
     }
}
