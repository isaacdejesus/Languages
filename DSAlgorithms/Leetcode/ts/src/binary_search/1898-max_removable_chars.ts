const is_subseq = (s: string, subseq: string, a_set: Set<number>): boolean =>
{
    let i1 = 0;
    let i2 = 0;
    while(i1 < s.length && i2 < subseq.length)
    {
        if(a_set.has(i1) || s[i1] !== subseq[i2])
        {
            i1++;
            continue;
        }
        i1++;
        i2++;
    }
    return i2 === subseq.length;
}
const maximumRemovals = (s: string, p: string, removable: number[]): number =>{
    let result = 0;
    let left = 0;
    let right = removable.length - 1;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) /2);
        const a_set = new Set<number>();
        for(let i = 0; i < mid + 1; i++)
            a_set.add(removable[i]);
        if(is_subseq(s, p, a_set))
        {
            result = Math.max(result, mid + 1);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return result;
    };