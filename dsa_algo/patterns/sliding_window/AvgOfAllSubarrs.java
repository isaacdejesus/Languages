import java.util.Arrays;
class AvgOfAllSubarrs 
{
    public static double[] find_avgs(int k, int[] arr)
    {
        double[] result = new double[arr.length - k + 1];
        double window_sum = 0;
        int window_start = 0;
        for(int window_end = 0; window_end < arr.length; window_end++)
        {
            window_sum += arr[window_end];
            if(window_end >= k - 1)
            {
                result[window_start] = window_sum / k;
                window_sum -= arr[window_start];
                window_start++;
            }
        }
        return result;
    }
    public static void main(String[] args)
    {
        double[] result = AvgOfAllSubarrs.find_avgs(5, new int[] {1, 3, 2, 6, -1, 4, 1, 8, 2});
        System.out.println("Avg of subarrays of size k: " + Arrays.toString(result));
    }
}
