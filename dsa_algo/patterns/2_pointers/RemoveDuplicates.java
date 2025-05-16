class RemoveDuplicates
{
    public static int remove(int[] arr)
    {
        int next_non_duplicate = 1;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[next_non_duplicate - 1] != arr[i])
            {
                arr[next_non_duplicate] = arr[i];
                next_non_duplicate++;
            }
        }
        return next_non_duplicate;
    }
    public static void main(String[] args)
    {
        int[] arr = new int[] {2, 3, 3, 3, 6, 9, 9};
        System.out.println(RemoveDuplicates.remove(arr));
        arr = new int[] {2, 2, 2, 11};
        System.out.println(RemoveDuplicates.remove(arr));
    }
}
