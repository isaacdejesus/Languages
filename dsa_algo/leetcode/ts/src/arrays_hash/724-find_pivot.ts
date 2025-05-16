const pivotIndex = (nums: number[]): number =>{
    let total_sum: number = 0;
    for(let i = 0; i < nums.length; i++)
       total_sum += nums[i];
    let left_sum = 0;
    for(let i = 0; i < nums.length; i++)
    {
        let right_sum = total_sum - left_sum - nums[i];
        if(right_sum === left_sum)
            return i;
        left_sum += nums[i];
    }
    return -1;
};
