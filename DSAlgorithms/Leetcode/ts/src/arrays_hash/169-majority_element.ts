const  majorityElement = (nums: number[]): number => {
    let count = 0;
    let majority_element = 0;
    for(let i = 0; i < nums.length; i++)
    {
        if(count === 0)
            majority_element = nums[i];
        if(majority_element === nums[i])
            count++;
        else 
            count--;
    }
    return majority_element;
    
}
