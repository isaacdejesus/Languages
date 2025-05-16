const singleNonDuplicate = (nums: number[]): number =>{
    let left = 0;
    let right = nums.length - 1;
    let result = 0;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if((mid - 1 < 0 || nums[mid - 1] !== nums[mid]) && (mid + 1 === nums.length || nums[mid] !== nums[mid + 1]))
        {
            result = nums[mid];
           return nums[mid];
        }
        let left_size = mid;
        if(nums[mid - 1] === nums[mid])
            left_size = mid - 1;
        if(left_size % 2 === 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result ;
};