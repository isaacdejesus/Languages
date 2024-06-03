import java.util.*;
class TripletWithSmallerSum
{
    public static int search_triplets(int[] arr, int target)
    {
        Arrays.sort(arr);
        int count = 0;
        for(int i = 0; i < arr.length - 2; i++)
            count+= search_pair(arr, target - arr[i], i);
        return count;
    }
    private static int search_pair(int[] arr, int target_sum, int first)
    {
        int count = 0;
        int left = first + 1;
        int right = arr.length - 1;
        while(left < right)
        {
            if(arr[left] + arr[right] < target_sum)
            {
                count += right - left;
                left++;
            }
            else
                right --;
        }
        return count;
    }
    public static void main(String[] args)
    {
        System.out.println(TripletSmallerSum.search_triplets(new int[] {-1, 0, 2, 3}, 3));
        System.out.println(TripletSmallerSum.search_triplets(new int[] {-1, 4, 2, 1, 3}, 5));
    }
}
