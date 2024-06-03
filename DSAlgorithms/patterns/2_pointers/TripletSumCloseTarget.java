import java.util.*;
class TripleSumCloseTarget
{
    public static int search_triplet(int[] arr, int target_sum)
    {
        if(arr == null || arr.length < 2)
            throw new IllegalArgumentException();
        Arrays.sort(arr);
        int smallest_dif = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length - 2; i++)
        {
            int left = i + 1;
            int right = arr.length - 1;
            while(left < right)
            {
                int target_dif = target_sum - arr[i] - arr[left] - arr[right];
                if(target_dif == 0)
                    return target_sum - target_dif;
                if(Math.abs(target_dif) < Math.abs(smallest_dif) || (Math.abs(target_dif) == 
                            Math.abs(smallest_dif) && target_dif > smallest_dif))
                    smallest_dif = target_dif;
                if(target_dif > 0)
                    left++;
                else right--;
            }

        }
        return target_sum - smallest_dif;
    }
    public static void main(String[] args)
    {
        System.out.println(TripleSumCloseTarget.search_triplet(new int[] {-2, 0, 1, 2}, 2));
        System.out.println(TripleSumCloseTarget.search_triplet(new int[] {-3, -1, 1, 2}, 1));
        System.out.println(TripleSumCloseTarget.search_triplet(new int[] {1, 0, 1, 1}, 100));
    }
}
