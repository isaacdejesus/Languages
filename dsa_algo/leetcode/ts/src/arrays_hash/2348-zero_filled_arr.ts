const zeroFilledSubarray = (nums: number[]): number =>{
    let count = 0;
    let result = 0;
    for(let i = 0; i < nums.length; i++)
    {
        if(nums[i] === 0)
            count++;
        else
            count = 0;
        result += count;
    }
    return result;
};