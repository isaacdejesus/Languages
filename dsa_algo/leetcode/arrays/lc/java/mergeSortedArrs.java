public class mergeSortedArrs{
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       int p1 = m - 1;
       int p2 = n - 1;
       for(int insert_loc = m + n - 1; insert_loc >= 0; insert_loc--) 
       {
            if(p2 < 0)
                break;
            if(p1 >= 0 && nums1[p1] > nums2[p2])
                nums1[insert_loc] = nums1[p1--];
            else
                nums1[insert_loc] = nums2[p2--];
       }
    }
}