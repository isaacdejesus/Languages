const canSum = (targetSum: number, numbers: number[]): boolean => {
    if(targetSum === 0)
        return true;
    if(targetSum < 0)
        return false;
    for(let num of numbers)
    {
        const remainder = targetSum - num;
        if(canSum(remainder, numbers) === true)
            return true;
    }
    return false;
};
const canSumMemoized = (targetSum: number, numbers: number[]): boolean => {
    const cache = new Map<number, boolean>();
    const inCache = cache.get(targetSum);
    if(inCache !== undefined)
        return inCache;
    if(targetSum === 0)
        return true;
    if(targetSum < 0)
        return false;
    for(let num of numbers)
    {
        const remainder = targetSum - num;
        if(canSumMemoized(remainder, numbers) === true)
        {
            cache.set(targetSum, true);
            return true;
        }
    }
    return false;
};

console.log(canSumMemoized(7, [ 4, 2]));
