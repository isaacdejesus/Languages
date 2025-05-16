const majorityElement = (nums: number[]): number => {
    let count = 0;
    let majority_element = 0;
    let numsSize = nums.length;
    for(let element = 0;  element < numsSize; element++)
    {
        if(count === 0 )
            majority_element = nums[element];
        if(majority_element === nums[element])
            count++;
        else
            count--;
    }
    return majority_element;
}
