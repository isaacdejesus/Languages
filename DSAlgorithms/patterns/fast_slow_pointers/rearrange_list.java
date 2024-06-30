class list_node {
    int value = 0;
    list_node next;
    list_node(int value)
    {
        this.value = value;
    }
}
class rearrange_list {
    public static void reorder(list_node head)
    {
        if(head == null || head.next == null)
            return;
        list_node slow = head;
        list_node fast = head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        list_node head_second_half = reverse(slow);
        list_node head_first_half = head;
        while(head_first_half != null && head_second_half != null)
        {
            list_node temp = head_first_half.next;
            head_first_half.next = head_second_half;
            head_first_half = temp;
            temp = head_second_half.next;
            head_second_half.next = head_first_half;
            head_second_half = temp;
        }
        if(head_first_half != null)
            head_first_half.next = null;
    }
    private static list_node reverse(list_node head)
    {
        list_node prev = null;
        while(head != null)
        {
            list_node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    public static void main(String[] args)
    {
        list_node head  = new list_node(2);
        head.next = new list_node(4);
        head.next.next = new list_node(6);
        head.next.next.next = new list_node(8);
        head.next.next.next.next = new list_node(10);
        head.next.next.next.next.next = new list_node(12);
        rearrange_list.reorder(head);
        while(head != null)
        {
            System.out.println(head.value + " ");
            head = head.next;
        }
    }
}
