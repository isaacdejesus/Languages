const removeDuplicates = (nums: number[]): number =>{
    let insert_loc = 0;
    let right = 0;
    while(right < nums.length)    
    {

        let current_duplicate_count = 1;
        while((right + 1 < nums.length) && nums[right] === nums[right + 1])
        {
            right++;
            current_duplicate_count++;
        }
        let duplicate_count = Math.min(2, current_duplicate_count);
        for(let i = 0; i < duplicate_count; i++)
        {
            nums[insert_loc] = nums[right];
            insert_loc++;
        }
        right++;
    }
    return insert_loc;
};