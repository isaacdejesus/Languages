/**
 Do not return anything, modify nums in-place instead.
 */
 const moveZeroes = (nums: number[]): void =>{
    let insert_loc = 0;
    for(let i = 0; i < nums.length; i++)
    {
        if(nums[i] != 0)
        {
            let temp = nums[insert_loc];
            nums[insert_loc] = nums[i];
            nums[i] = temp;
            insert_loc++;
        }
    }
};