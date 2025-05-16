const find132pattern = (nums: number[]): boolean =>{
    const val_stack: number[] = [];
    const min_left_stack: number[] = [];
    let current_min = nums[0];
    for(let i = 1; i < nums.length; i++)
    {
        while(val_stack.length > 0 && nums[i] >= val_stack[val_stack.length - 1])
        {
            val_stack.pop();
            min_left_stack.pop();
        }
        if(val_stack.length > 0 && nums[i] > min_left_stack[min_left_stack.length - 1])
            return true;
        val_stack.push(nums[i]);
        min_left_stack.push(current_min);
        current_min = Math.min(current_min, nums[i]);
    }
    return false;
};