class list_node {
    int value = 0;
    list_node next;
    list_node(int value)
    {
        this.value = value;
    }
}

class palindromic_linked_list {
    public static boolean is_palindrome(list_node head)
    {
        if(head == null || head.next == null)
            return true;
        list_node slow = head;
        list_node fast =head;
        while(fast != null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        list_node head_second_half = reverse(slow);
        list_node cp_head_second_half = head_second_half;
        while(head != null && head_second_half != null)
        {
            if(head.value != head_second_half.value)
                break;
            head = head.next;
            head_second_half = head_second_half.next;
        }
        reverse(cp_head_second_half);
        if(head == null || head_second_half == null)
            return true;
        return false;
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
        list_node head = new list_node(2);
        head.next = new list_node(4);
        head.next.next = new list_node(6);
        head.next.next.next = new list_node(4);
        head.next.next.next.next = new list_node(2);
        System.out.println("is palindrome: " + palindromic_linked_list.is_palindrome(head));

        head.next.next.next.next.next = new list_node(2);
        System.out.println("is palindrome: " + palindromic_linked_list.is_palindrome(head));
     }
}
