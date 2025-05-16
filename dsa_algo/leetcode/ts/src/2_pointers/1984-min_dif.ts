const minimumDifference  = (nums: number[], k: number): number  => {
    nums.sort((a, b) => a - b);
    console.log(nums);
    let left = 0;
    let right = k - 1;
    let result = Infinity;
    while(right < nums.length)
    {
        result = Math.min(result, (nums[right] - nums[left]));
        left++;
        right++;
    }
    return result;
};