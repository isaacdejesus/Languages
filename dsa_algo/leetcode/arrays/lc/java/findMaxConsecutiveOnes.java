class findMaxConsecutiveOnes {
    public static int f(int[] nums)
    {
        int max_count = 0;
        int current_count = 0;
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] == 0)
            {
                max_count = Math.max(max_count, current_count);
                current_count = 0;
            }
            else
                current_count++;
        }
        return Math.max(max_count, current_count);
    }
    public static void main(String[] args)
    {
        int[] arr = {1, 1, 0, 1, 1, 1};
        System.out.println(findMaxConsecutiveOnes.f(arr));
    }
}
