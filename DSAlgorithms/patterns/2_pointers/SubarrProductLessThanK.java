import java.util.*;
class SubarrProductLessThanK {
    public static List<List<Integer>> find_subarrays(int[] arr, int target)
    {
        List<List<Integer>> result = new ArrayList<>();
        int product = 1;
        int left = 0;
        for(int right = 0; right < arr.length; right++)
        {
            product *= arr[right];
            while(product >= target && left < arr.length)
                product /= arr[left++];
            List<Integer> temp_list = new LinkedList<>();
            for(int i = right; i >= left; i--)
            {
                temp_list.add(0, arr[i]);
                result.add(new ArrayList<>(temp_list));
            }
        }
        return result;
    }
    public static void main(String[] args)
    {
       System.out.println(SubarrProductLessThanK.find_subarrays(new int[] {2, 5, 3, 10}, 30));
       System.out.println(SubarrProductLessThanK.find_subarrays(new int[] {8, 2, 6, 5}, 50));
    }
}
