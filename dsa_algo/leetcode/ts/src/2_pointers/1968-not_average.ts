const rearrangeArray = (nums: number[]): number[] =>{
    nums.sort((a, b) => a - b);
    const result: number[] = [];
    let left = 0;
    let right = nums.length - 1;
    while(result.length != nums.length)
    {
        result.push(nums[left]);
        left++;
        if(left <= right)
        {
            result.push(nums[right]);
            right--;
        }
    }
    return result;
};