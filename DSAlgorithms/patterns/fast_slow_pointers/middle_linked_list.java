class list_node {
    int value = 0;
    list_node next;
    list_node(int value)
    {
        this.value = value;
    }
}
class middle_linked_list {
    public static list_node find_mid(list_node head)
    {
        list_node slow = head;
        list_node fast = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public static void main(String[] args)
    {
        list_node head = new list_node(1);
        head.next = new list_node(2);
        head.next.next = new list_node(3);
        head.next.next.next = new list_node(4);
        head.next.next.next.next = new list_node(5);
        System.out.println("middle node: " + middle_linked_list.find_mid(head).value);

        head.next.next.next.next.next = new list_node(6);
        System.out.println("middle node: " + middle_linked_list.find_mid(head).value);

        head.next.next.next.next.next.next = new list_node(7);
        System.out.println("middle node: " + middle_linked_list.find_mid(head).value);
    }
}
