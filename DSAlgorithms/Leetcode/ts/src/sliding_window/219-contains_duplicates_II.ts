const containsNearbyDuplicate = (nums: number[], k: number): boolean =>{
    const window = new Set<number>();
    let left = 0;
    for(let right = 0; right < nums.length; right++)
    {
        if(right - left  > k)
        {
            window.delete(nums[left]);
            left++;
        }
        if(window.has(nums[right]))
            return true;
        window.add(nums[right]);
    }
    return false;

};