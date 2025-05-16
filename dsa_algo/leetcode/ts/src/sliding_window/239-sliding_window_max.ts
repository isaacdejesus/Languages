const maxSlidingWindow = (nums: number[], k: number): number[] =>{
    //eh, js doesn't have a built in deque. using arr for now
    //it works so whatever
    const result : number[] = [];
    const dq: number[] = [];
    let left = 0;
    let right = 0;
    while(right < nums.length)
    {
        while((dq.length > 0) && nums[dq[dq.length - 1]] < nums[right])
            dq.pop();
        dq.push(right);
        if(left > dq[0])
            dq.shift();
        if((right + 1) >= k)
        {
            result.push(nums[dq[0]])
            left++;
        }
        right++;
    }
    return result;
};