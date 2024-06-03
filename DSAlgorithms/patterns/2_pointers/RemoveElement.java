class RemoveElement
{
    public static int remove(int[] arr, int key)
    {
        int next_element = 0;
        for(int i = 0; i < arr.length; i++)
        {
            if(arr[i] != key)
            {
                arr[next_element] = arr[i];
                next_element++;
            }
        }
        return next_element;
    }
    public static void main(String[] args)
    {
        int[] arr = new int[] {3, 2, 3, 6, 3, 10, 9, 3};
        System.out.println(RemoveElement.remove(arr, 3));
        arr = new int[] { 2, 11, 2, 2, 1};
        System.out.println(RemoveElement.remove(arr, 2));
    }
}
