const minSubArrayLen = (target: number, nums: number[]): number =>{
    let left = 0;
    let total = 0;
    let result = Infinity;
    for(let right = 0; right < nums.length; right++)
    {
        total += nums[right];
        while(total >= target)
        {
            result = Math.min(right - left + 1, result);
            total -= nums[left];
            left++;
        }
    }
    if(result === Infinity)
        return 0;
    return result;
};