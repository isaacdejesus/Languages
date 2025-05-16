const productExceptSelf = (nums: number[]): number[] =>{
    const size_of_arr = nums.length;
    const result: number[] = new Array(size_of_arr);
    result.fill(1);
    let prefix: number = 1;
    for(let i = 0; i < size_of_arr; i++)
    {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }
    let postfix: number = 1;
    for(let i = size_of_arr - 1; i >= 0; i--)
    {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }
    return result;
};
