class ReplacingOnes 
{
    public static int find_length(int[] arr, int k)
    {
        int window_start = 0;
        int max_length = 0;
        int max_ones_count = 0;
        for(int window_end = 0; window_end < arr.length; window_end++)
        {
            if(arr[window_end] == 1)
                max_ones_count++;
            if(window_end - window_start + 1 - max_ones_count > k)
            {
                if(arr[window_start] == 1)
                    max_ones_count--;
                window_start++;
            }
            max_length = Math.max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
    public static void main(String[] args)
    {
        System.out.println(ReplacingOnes.find_length(new int[] {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2));
        System.out.println(ReplacingOnes.find_length(new int[] {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3));
    }
}
