class MinSubarrSum
{
    public static int find_min_subarr(int s, int[] arr)
    {
        int window_sum = 0;
        int min_length = Integer.MAX_VALUE;
        int window_start = 0;
        for(int window_end = 0; window_end < arr.length; window_end++)
        {
            window_sum += arr[window_end];
            while(window_sum >= s)
            {
                min_length = Math.min(min_length, window_end - window_start + 1);
                window_sum -= arr[window_start];
                window_start++;
            }
        }
        return min_length == Integer.MAX_VALUE ? 0 : min_length;
    }
    public static void main(String[] args)
    {
        int result = MinSubarrSum.find_min_subarr(7, new int[] {2, 1, 5, 2, 3, 2});
        System.out.println("Smallest subarray length: " + result);
        result = MinSubarrSum.find_min_subarr(7, new int[] {2, 1, 5, 2, 8});
        System.out.println("Smallest subarray length: " + result);
        result = MinSubarrSum.find_min_subarr(8, new int[] {3, 4, 1, 1, 6});
        System.out.println("Smallest subarray length: " + result);
    }
}
