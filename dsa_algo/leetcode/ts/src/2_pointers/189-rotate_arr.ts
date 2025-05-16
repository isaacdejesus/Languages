/**
 Do not return anything, modify nums in-place instead.
 */
 const rotate = (nums: number[], k: number): void =>{
    k = k % nums.length;
    let left = 0;
    let right = nums.length - 1;
    while(left < right)
    {
        let temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    left = 0;
    right = k - 1;
    while(left < right)
    {
        let temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    left = k;
    right = nums.length - 1;
    while(left < right)
    {
        let temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

};