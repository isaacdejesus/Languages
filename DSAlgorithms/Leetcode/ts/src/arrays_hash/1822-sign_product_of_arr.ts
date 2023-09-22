const arraySign = (nums: number[]): number =>{
    let sign: number = 0;
    for(let i = 0; i < nums.length; i++)
    {
        if(nums[i] === 0)
            return 0;
        if(nums[i] < 0)
            sign++;
    }
        return Math.floor(sign % 2) === 0 ? 1 : -1;
    
};
