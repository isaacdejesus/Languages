const sortedSquares = (nums: number[]): number[] =>{
    const result: number[] = [];
    let right = nums.length - 1;
    let left = 0
    while(left <= right)
    {
        if(nums[left] * nums[left] > nums[right] * nums[right])
        {
            result.push(nums[left] * nums[left]);
            left++;
        }
        else
        {
            result.push(nums[right] * nums[right]);
            right--;
        }
    }
    result.reverse();
    return result;
};