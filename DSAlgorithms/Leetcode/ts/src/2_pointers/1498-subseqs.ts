const numSubseq  = (nums: number[], target: number): number =>{
    nums.sort((a, b) => a - b);
    let result = 0;
    let left = 0;
    let right = nums.length - 1;
    const mod = Math.pow(10, 9) + 7;
    const pows: number[] = new Array(nums.length).fill(1);
    for(let i = 1; i < nums.length; i++)
        pows[i] = (pows[i - 1] << 1) % mod;
        
    while(left <= right)
    {
        if((nums[left] + nums[right]) <= target)
        {
            result = (result + pows[right - left]) % mod;
            left++;
        }
        else
            right--;
    }
    return result ;
};