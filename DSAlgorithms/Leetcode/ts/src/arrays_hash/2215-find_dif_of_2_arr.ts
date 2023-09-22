const findDifference  = (nums1: number[], nums2: number[]): number[][] =>{
    const set1 = new Set<number>();
    const set2 = new Set<number>();
    const ans1 = new Set<number>();
    const ans2 = new Set<number>();
    const res1: number[] = [];
    const res2: number[] = [];
    const result: number [][] = [];
    for(let i = 0; i < nums1.length; i++)
        set1.add(nums1[i]);
    for(let i = 0; i < nums2.length; i++)
        set2.add(nums2[i]);
    for(let i = 0; i < nums1.length; i++)
        if(!set2.has(nums1[i]))
            ans1.add(nums1[i]);
    for(let i = 0; i < nums2.length; i++)
        if(!set1.has(nums2[i]))
            ans2.add(nums2[i]);
    for(let item of ans1)
        res1.push(item);
    for(let item of ans2)
        res2.push(item);
    result.push(res1);
    result.push(res2);
    return result;
};