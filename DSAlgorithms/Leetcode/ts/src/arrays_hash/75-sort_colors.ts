const swap = (arr: number[], i: number, j: number): number[] => {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return arr;
}

const sortColors = (nums: number[]): void => {
    let left: number = 0;
    let right: number = nums.length - 1;
    for(let i = left; i <= right; i++)
    {
        if(nums[i] === 0)
        {
            swap(nums, i, left);
            left++;
        }
        if(nums[i] === 2)
        {
            swap(nums, i, right);
            right--;
            i--;
        }
    }
}
