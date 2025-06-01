class insert{
    public static void main(String[] args) 
    {
        //inserting at end of arck of insert loc
        //insert_loc to keep track of insert lo
        int[] arr = new int[6];
        int insert_loc = 0;
        //insert 3 items
        for(int i = 0; i < 3; i++)
        {
            arr[insert_loc] = i;
            insert_loc++;
        }
        //current arr [0, 1, 2]
        //insert another item at end
        arr[insert_loc] = 10;
        insert_loc++;
        //current arr [0, 1, 2, 10]

        //insert at start of arr
        //Need to shift all elements to the right by 1
        //Start shifting from the back to avoid overwriting values
        for(int i = 3; i >=0; i--)
            arr[i + 1] = arr[i];
        //insert new element at [0]
        arr[0] = 20;
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);
        //current arr [10, 0, 1, 2, 10, 0]

        //insert anywhere in arr
        //Shift all elements to the right starting from insert index 
        //then insert new element at insert index
    }
}
