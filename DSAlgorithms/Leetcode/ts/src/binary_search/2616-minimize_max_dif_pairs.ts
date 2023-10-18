const is_valid = (threshold: number, p: number, nums: number[]): boolean => {
    let i = 0;
    let count = 0;
    while(i < nums.length - 1)
    {
        if(Math.abs(nums[i] - nums[i + 1]) <= threshold)
        {
            count++;
            i +=2;
        }
        else 
            i++;
        if(count === p)
            return true;
    }
    return false;
}
const minimizeMax = (nums: number[], p: number): number =>{
    nums.sort((a, b) => a - b);
    let left = 0;
    let right = Math.pow(10, 9);
    let result = 0;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if(is_valid(mid, p, nums))
        {
            result = mid;
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }
    return result;
};