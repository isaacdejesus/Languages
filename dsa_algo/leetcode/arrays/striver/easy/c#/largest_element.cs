using System;
public class Solution {
    public int largest_element(int[] nums)
    {
        int largest = nums[0];
        for(int i = 1; i < nums.Length; i++)
        {
            if(nums[i] > largest)
                largest = nums[i];
        }
        return largest;
    }
}
public class program {
    public static void Main(string[] args)
    {
        int[] nums = { 3, 2, 1, 5, 2 };
        Solution largest = new Solution();
        Console.WriteLine(largest.largest_element(nums));
    }
}
