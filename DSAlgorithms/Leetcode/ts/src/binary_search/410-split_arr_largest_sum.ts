const can_split = (largest: number, nums: number[], m: number): boolean => {
    let sub_arr = 0;
    let current_sum = 0;
    for(let i = 0; i < nums.length; i++)
    {
        current_sum += nums[i];
        if(current_sum > largest)
        {
            sub_arr++;
            current_sum = nums[i];
        }
    }
    return sub_arr + 1 <= m;
}

const splitArray = (nums: number[], k: number): number =>{
    let left = Math.max(...nums);
    let right = 0;
    for(let i = 0; i < nums.length; i++)
            right += nums[i];
    let result = right;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if(can_split(mid, nums, k))
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return result;
};