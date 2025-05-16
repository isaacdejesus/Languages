import java.util.Arrays;

class AvgOfAllSubarrsBrute {
    public static double[] find_avgs(int k, int[] arr)
    {
        double[] result = new double[arr.length - k + 1];
        for(int i = 0; i <= arr.length -k; i++)
        {
            double sum = 0;
            for(int j = i; j < i + k; j++)
                sum += arr[j];
            result[i] = sum/k;
        }
        return result;
    }
    public static void main(String[] args)
    {
        double[] result = AvgOfAllSubarrsBrute.find_avgs(5, new int[] {1, 3, 2, 6, -1, 4, 1, 8, 2});
        System.out.println("avg of subarrays of size k: " + Arrays.toString(result));
    }
}
