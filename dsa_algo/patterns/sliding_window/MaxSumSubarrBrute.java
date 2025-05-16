class MaxSumSubarrBrute {
    public static int find_max_sum_subarr(int k, int[] arr)
    {
        int max_sum = 0;
        int window_sum = 0;
        for(int i = 0; i <= arr.length - k; i++)
        {
            window_sum = 0;
            for(int j = i; j < i + k; j++)
                window_sum += arr[j];
            max_sum = Math.max(max_sum, window_sum);
        }
        return max_sum;
    }
    public static void main(String[] args)
    {
        System.out.println("Max sum of a subarray of size k: " + 
                MaxSumSubarrBrute.find_max_sum_subarr(3, new int[] {2, 1, 5, 1, 3, 2}));

        System.out.println("Max sum of a subarray of size k: " + 
                MaxSumSubarrBrute.find_max_sum_subarr(2, new int[] {2, 3, 4, 1, 5}));
    }
}
