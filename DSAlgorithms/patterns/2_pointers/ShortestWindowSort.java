class ShortestWindowSort {
    public static int sort(int[] arr)
    {
        int low = 0, high = arr.length - 1;
        while(low < arr.length - 1 && arr[low] <= arr[low + 1])
            low++;
        if(low == arr.length - 1)
            return 0;
        while(high > 0 && arr[high] >= arr[high - 1])
            high--;
        int sub_arr_max = Integer.MIN_VALUE;
        int sub_arr_min = Integer.MAX_VALUE;
        for(int k = low; k <= high; k++)
        {
            sub_arr_max = Math.max(sub_arr_max, arr[k]);
            sub_arr_min = Math.min(sub_arr_min, arr[k]);
        }
        while(low > 0 && arr[low -1] > sub_arr_min)
            low--;
        while(high < arr.length - 1 && arr[high + 1] < sub_arr_max)
            high++;
        return high - low + 1;
    }
    public static void main(String[] args)
    {
        System.out.println(ShortestWindowSort.sort(new int[] {1, 2, 5, 3, 7, 10, 9 ,12}));
        System.out.println(ShortestWindowSort.sort(new int[] {1, 3, 2, 0, -1, 7, 10}));
        System.out.println(ShortestWindowSort.sort(new int[] {1, 2, 3}));
        System.out.println(ShortestWindowSort.sort(new int[] {3, 2, 1}));
    }
}
