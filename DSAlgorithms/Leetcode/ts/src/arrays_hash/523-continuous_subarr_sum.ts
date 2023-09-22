const checkSubarraySum = (nums: number[], k: number): boolean =>{
    const hash = new Map<number, number> ();
    hash.set(0, -1);
    let total: number = 0;
    for(let i = 0; i < nums.length; i++)
    {
        total += nums[i];
        let remainder: number = total % k;
        if(!hash.has(remainder))
            hash.set(remainder, i);
        else if((i - hash.get(remainder)) > 1)
            return true;
    }
    return false;

};