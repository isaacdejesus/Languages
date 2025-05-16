const subarraySum = (nums: number[], k: number): number =>{
    let result: number = 0;
    let current_sum: number = 0;
    const hash = new Map<number, number>();
    hash.set(0,1);
    for(let i = 0; i < nums.length; i++)
    {
        current_sum += nums[i];
        let val_needed = current_sum - k;
        if(hash.has(val_needed))
            result += hash.get(val_needed);
        if(hash.has(current_sum))
        {
            const current_val = hash.get(current_sum)
            hash.set(current_sum, current_val + 1);
        }
        else
        {
            hash.set(current_sum, 1);
        }
    }
    return result;
};