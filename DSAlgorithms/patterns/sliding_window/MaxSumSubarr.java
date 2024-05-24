class MaxSumSubarr {
    public static int find_max_subarr(int k, int[] arr)
    {
        int window_sum = 0;
        int max_sum = 0;
        int window_start = 0;
        for(int window_end = 0; window_end < arr.length; window_end++)
        {
            window_sum += arr[window_end];
            if(window_end >= k - 1)
            {
                max_sum = Math.max(max_sum, window_sum);
                window_sum -= arr[window_start];
                window_start++;
            }
        }
        return max_sum;
    }
    public static void main(String[] args)
    {
        System.out.println("Max sum of a subarray of size k: " + 
                MaxSumSubarr.find_max_subarr(3, new int[] {2, 1, 5, 1, 3, 2}));
        System.out.println("Max sum of a subarray of size k: " + 
                MaxSumSubarr.find_max_subarr(2, new int[] {2, 3, 4, 1, 5}));
    }
}
