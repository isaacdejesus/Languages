const twoSum = (nums:number[], target:number): number[] => {
    const values = new Map();
    for(let i = 0; i < nums.length; i++){
        const targetMatch = target - nums[i];
        const matchingVal = values.get(targetMatch);
        if(matchingVal !== undefined)
            return [matchingVal, i];
        values.set(nums[i], i);
    };
    return [0];
};
const arr = [3, 4, 5, 1];
console.log(twoSum(arr, 4));
