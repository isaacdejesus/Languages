const nextGreaterElement = (nums1: number[], nums2: number[]): number[] =>{
    const a_stack: number[] = [];
    const result: number[] = Array(nums1.length).fill(-1);
    const a_hash = new Map<number, number>();
    for(let i = 0; i < nums1.length; i++)
        a_hash.set(nums1[i], i);
    for(let i = 0; i < nums2.length; i++)
    {
        let current = nums2[i];
        while(a_stack.length > 0 && current > a_stack[a_stack.length - 1])
        {
            let val = a_stack[a_stack.length - 1];
            a_stack.pop();
            let index = a_hash.get(val);
            result[index] = current;
        }
        if(a_hash.has(current))
            a_stack.push(current);
    }
    return result;
};
