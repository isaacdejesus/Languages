const topKFrequent = (nums: number[], k: number): number[] => {
    let arr_size = nums.length;
    const hash = new Map<number, number>();
    for(let i = 0; i < arr_size; i++)
    {
        if(hash.has(nums[i]))
        {
            let current_val = hash.get(nums[i])
            hash.set(nums[i], current_val + 1);
        }
        else 
            hash.set(nums[i], 1);
    }
    const buckets: number[][] = new Array(arr_size + 1);
    for(let i = 0; i < arr_size + 1; i++)
        buckets[i] = new Array();
    hash.forEach((value, key) => {
            buckets[value].push(key);
    });
    const result: number[] = [];
    for(let i = arr_size; i >= 0; i--)
    {
        if(result.length >= k)
            break;
        if(buckets[i].length > 0)
            result.push(...buckets[i]);
    }
    return result;

};
