class PairTargetSum {
    public static int [] search(int[] arr, int target_sum)

    {
        int left = 0;
        int right = arr.length - 1;
        while(left < right)
        {
            int current_sum = arr[left] + arr[right];
            if(current_sum == target_sum)
                return new int[] {left, right};
            if(target_sum > current_sum)
                left++;
            else
                right--;
        }
        return new int[] {-1, -1};
    }
    public static void main(String[] args)
    {
        int[]  result = PairTargetSum.search(new int[] {1, 2, 3, 4, 6}, 6);
        System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
        result = PairTargetSum.search(new int[] {2, 5, 9, 11}, 11);
        System.out.println("Pair with target sum: [" + result[0] + ", " + result[1] + "]");
    }
}
