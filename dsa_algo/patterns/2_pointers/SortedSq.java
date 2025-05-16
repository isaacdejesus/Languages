class SortedSq
{
    public static int[] make_squares(int[] arr)
    {
        int n = arr.length;
        int[] squares = new int[n];
        int highest_sq_index = n - 1;
        int left = 0;
        int right = arr.length - 1;
        while(left <= right)
        {
            int left_sq = arr[left] * arr[left];
            int right_sq = arr[right] * arr[right];
            if(left_sq > right_sq)
            {
                squares[highest_sq_index--] = left_sq;
                left++;
            }
            else
            {
                squares[highest_sq_index--] = right_sq;
                right--;
            }
        }
        return squares;
    }
    public static void main(String[] args)
    {
        int[] result = SortedSq.make_squares(new int[] {-2, -1, 0, 2, 3});
        for(int num: result)
            System.out.print(num + " ");
        System.out.println();
        result = SortedSq.make_squares(new int[] {-3, -1, 0, 1, 2});
        for(int num: result)
            System.out.print(num + " ");
        System.out.println();
    }
}
