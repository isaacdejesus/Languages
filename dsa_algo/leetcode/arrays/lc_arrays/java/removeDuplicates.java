public class removeDuplicates {
    public static int remove_duplicates(int[] nums) {
       int insert_loc = 1;
       for(int i = 1; i < nums.length; i++) 
       {
            if(nums[i] != nums[i - 1])
            {
                nums[insert_loc] = nums[i];
                insert_loc++;
            }
       }
       return insert_loc;
    }
}