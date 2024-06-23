import java.util.*;
class QuadSumTarget {
    public static List<List<Integer>> search_quad(int[] arr, int target)
    {
        Arrays.sort(arr);
        List<List<Integer>> quadruplets = new ArrayList<>();
        for(int i = 0; i < arr.length - 3; i++)
        {
            if(i > 0 && arr[i] == arr[i - 1])
                continue;
            for(int j = i + 1; j < arr.length - 2; j++)
            {
                if(j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                search_pairs(arr, target, i , j, quadruplets);
            }
        }
        return quadruplets;
    }
    private static void search_pairs(int[] arr, int target_sum, int first, int second, List<List<Integer>> quadruplets)
    {
        int left = second + 1;
        int right = arr.length - 1;
        while(left < right)
        {
            int sum = arr[first] + arr[second] + arr[left] + arr[right];
            if(sum == target_sum)
            {
                quadruplets.add(Arrays.asList(arr[first], arr[second], arr[left], arr[right]));
                left++;
                right--;
                while(left < right && arr[left] == arr[left - 1])
                    left++;
                while(left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if(sum < target_sum)
                left++;
            else right--;
        }
    }
    public static void main(String[] args)
    {
        System.out.println(QuadSumTarget.search_quad(new int[] {4, 1, 2, -1, 1, -3}, 1));
        System.out.println(QuadSumTarget.search_quad(new int[] {2, 0, -1, 1, -2, 2}, 2));
    }
}
