import java.util.*;
class TripletSumZero
{
    public static List<List<Integer>> search_triplets(int[] arr)
    {
        Arrays.sort(arr);
        List<List<Integer>> triplets = new ArrayList<>();
        for(int i = 0; i < arr.length - 2; i++)
        {
            if(i > 0 && arr[i] == arr[i - 1])
                continue;
            search_pair(arr, -arr[i], i + 1, triplets);
        }
        return triplets;
    }
    private static void search_pair(int[] arr, int target_sum, int left, List<List<Integer>> triplets)
    {
        int right = arr.length - 1;
        while(left < right)
        {
            int current_sum = arr[left] + arr[right];
            if(current_sum == target_sum)
            {
                triplets.add(Arrays.asList(-target_sum, arr[left], arr[right]));
                left++;
                right--;
                while(left < right && arr[left] == arr[left - 1])
                    left++;
                while(left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if(target_sum > current_sum)
                left++;
            else
                right--;
        }
    }
    public static void main(String[] args)
    {
        System.out.println(TripletSumZero.search_triplets(new int[] {-3, 0, 1, 2, -1, 1, -2}));
        System.out.println(TripletSumZero.search_triplets(new int[] {-5, 2, -1, -2, 3}));
    }
}
