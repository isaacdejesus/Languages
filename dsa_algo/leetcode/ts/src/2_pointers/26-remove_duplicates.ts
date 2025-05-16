const removeDuplicates = (nums: number[]): number =>{
    let insert_loc = 1;
    for(let i = 1; i < nums.length; i++)
    {
        if(nums[i] != nums[i - 1])
        {
            nums[insert_loc] = nums[i];
            insert_loc++;
        }
    }
    return insert_loc;

};