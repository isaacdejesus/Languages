/**
 Do not return anything, modify nums1 in-place instead.
 */
 const merge = (nums1: number[], m: number, nums2: number[], n: number): void =>{
    let insert_loc = m + n - 1;
    while(m > 0 && n > 0)
    {
        if(nums1[m - 1] > nums2[n - 1])
        {
            nums1[insert_loc] = nums1[m - 1];
            m --;
        }
        else
        {
            nums1[insert_loc] = nums2[n - 1];
            n--;
        }
        insert_loc --;
    }
    while(n > 0)
    {
        nums1[insert_loc] = nums2[n - 1];
        n--;
        insert_loc--;
    }
};