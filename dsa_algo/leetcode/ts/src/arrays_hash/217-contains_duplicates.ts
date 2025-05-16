const contains_duplicates = (nums:number[]): boolean => {
    const hash = new Map<number, number>();
    for(let i = 0; i < nums.length; i++)
    {
        if(hash.get(nums[i]))
            return true;
        hash.set(nums[i], 1);
    }
    return false;
};

let arr: number[] = [1, 2, 3, 2, 4, 5];

console.log(contains_duplicates(arr));

