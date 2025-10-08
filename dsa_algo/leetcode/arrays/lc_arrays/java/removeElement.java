public class removeElement{
    public static int remove_element(int[] nums, int val)
    {
        int insert_loc = 0;
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] != val)
            {
                nums[insert_loc] = nums[i];
                insert_loc++;
            }
        }
        return insert_loc;
        
    }
}