const removeElement = (nums: number[], val: number): number => {
    let current_index = 0;
    for(let i = 0; i < nums.length; i++)
    {
        if(nums[i] !== val)
        {
            nums[current_index] = nums[i];
            current_index++;
        }
    }
    return current_index;
};
