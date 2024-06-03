import java.util.*;
class TripleSmallerSum
{
    public static List<List<Integer>> search_triplets(int[] arr, int target)
    {
        Arrays.sort(arr);
        List<List<Integer>> triplets = new ArrayList<>();
        for(int i = 0; i < arr.length - 2; i++)
            search_pair(arr, target - arr[i], i, triplets);
        return triplets;
    }
    private static void search_pair(int[] arr, int target_sum, int first, List<List<Integer>> triplets)
    {
        int left = first + 1;
        int right = arr.length - 1;
        while(left < right)
        {
            if(arr[left] + arr[right] < target_sum)
            {
                for(int i = right; i > left; i--)
                    triplets.add(Arrays.asList(arr[first], arr[left], arr[i]));
                left++;
            }
            else
                right --;
        }
    }
    public static void main(String[] args)
    {
        System.out.println(TripleSmallerSum.search_triplets(new int[] {-1, 0, 2, 3}, 3));
        System.out.println(TripleSmallerSum.search_triplets(new int[] {-1, 4, 2, 1, 3}, 5));
    }
}
