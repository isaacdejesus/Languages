class DutchFlag {
    public static void sort(int[] arr)
    {
        int low = 0;
        int high = arr.length - 1;
        for(int i = 0; i <= high;)
        {
            if(arr[i] == 0)
            {
                swap(arr, i, low);
                i++;
                low++;
            }
            else if(arr[i] == 1)
                i++;
            else
            {
                swap(arr, i, high);
                high--;
            }
        }
    }
    private static void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void main(String[] args)
    {
        int[] arr = new int[] {1, 0, 2, 1, 0};
        DutchFlag.sort(arr);
        for(int num : arr)
            System.out.print(num + " ");
        System.out.println();
        arr = new int[] {2, 2, 0, 1, 2, 0};
        DutchFlag.sort(arr);
        for(int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }
}
