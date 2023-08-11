const findDisappearedNumbers = (nums: number[]): number[] =>{
    for(let i = 0; i < nums.length; i++)
    {
        let current = Math.abs(nums[i]);
        nums[current - 1] = 0 - Math.abs(nums[current - 1]);
    }
    const result: number[] = [];
    for(let i = 0; i <= nums.length; i++)
    {
        if(nums[i - 1] > 0)
            result.push(i);
    }
    return result;
};
