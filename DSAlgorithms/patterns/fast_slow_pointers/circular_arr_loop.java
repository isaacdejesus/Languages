class circular_arr_loop {
    public static boolean loop_exists(int[] arr)
    {
        for(int i = 0; i < arr.length; i++)
        {
            boolean is_forward = arr[i] >= 0;
            int slow = i;
            int fast = i;
            do{
                slow = find_next_index(arr, is_forward, slow);
                fast = find_next_index(arr, is_forward, fast);
                if(fast != -1)
                    fast = find_next_index(arr, is_forward, fast);
            }
            while(slow != -1 && fast != -1 && slow != fast);
            if(slow != -1 && slow == fast)
                return true;
        }
        return false;
    }
    private static int find_next_index(int[] arr, boolean is_forward, int current_index)
    {
        boolean direction = arr[current_index] >= 0;
        if(is_forward != direction)
            return -1;
        int next_index = (current_index + arr[current_index]) % arr.length;
        if(next_index < 0)
            next_index += arr.length;
        if(next_index == current_index)
            next_index--;
        return next_index;
    }
    public static void main(String[] args)
    {
        System.out.println(circular_arr_loop.loop_exists(new int[] {1, 2, -1, 2, 2}));
        System.out.println(circular_arr_loop.loop_exists(new int[] {2, 2, -1, 2}));
        System.out.println(circular_arr_loop.loop_exists(new int[] {2, 1, -1, -2}));
    }
}
