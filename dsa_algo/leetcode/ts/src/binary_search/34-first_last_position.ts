const first_last_helper = (nums: number[], target: number, find_start: boolean): number => {

    let ans = -1;
    let left = 0;
    let right = nums.length - 1;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if(target < nums[mid])
            right = mid - 1;
        else if(target > nums[mid])
            left = mid + 1;
        else //found target
        {
            ans = mid;
            if(find_start) //if looking for start, check left side
                right = mid - 1;
            else  //looking for last occurrence, check right
                left = mid + 1;
        }
    }
    return ans;
}
const searchRange = (nums: number[], target: number): number[] => {
    const result: number[] = [-1, -1];
    result[0] = first_last_helper(nums, target, true);
    result[1] = first_last_helper(nums, target, false);
    return result;
};