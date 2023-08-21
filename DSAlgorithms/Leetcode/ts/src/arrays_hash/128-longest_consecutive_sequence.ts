const longestConsecutive = (nums: number[]): number =>{
    const set = new Set<number>();
    for(let i = 0; i < nums.length; i++)
        set.add(nums[i]);
    let longest = 0;
    set.forEach(element => {
        if(!set.has(element - 1))
        {
            let length = 1;
            while(set.has(element + length))
            ++length;
            longest = Math.max(longest, length);
        }
    })
    return longest;
};
