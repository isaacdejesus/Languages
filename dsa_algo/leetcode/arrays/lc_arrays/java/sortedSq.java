import java.util.Arrays;
import java.lang.Math;
class sortedSq {
    //space O(n log n);
    public static int[] sorted_sq1(int[] nums)
    {
        int arr_length = nums.length;
        int[] ans = new int[arr_length];
        for(int i = 0; i < arr_length; i++)
            ans[i] = nums[i] * nums[i];
        Arrays.sort(ans);  //O(nlogn) due to sort
        return ans;
    }
    public static int[] sorted_sq2(int[] nums)
    {
        int arr_length = nums.length;
        int[] result = new int[arr_length];
        int left = 0;
        int right = arr_length - 1;
        for(int i = arr_length - 1; i >= 0; i--)
        {
            int sq;
            if(Math.abs(nums[left]) < Math.abs(nums[right]))
            {
                sq = nums[right];
                right--;
            }
            else
            {
                sq = nums[left];
                left++;
            }
            result[i] = sq * sq;
        }
        return result;

    }
    public static void main(String[] args)
    {
        int[] arr1 = {-4, -1, 0, 3, 10};
        int[] arr2 = {-7, -3, 2, 3, 11};
        int[] res1 = sortedSq.sorted_sq1(arr1);
        for(int num: res1)
            System.out.print(num);
        System.out.println();
        int[] res2 = sortedSq.sorted_sq2(arr2);
        for(int num: res2)
            System.out.print(num);
    }
}
