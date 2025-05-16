const groupAnagrams = (strs: string[]): string[][] =>{
    const result: string[][] = [];
    const hash = new Map<string, string[]>();
    for(let i = 0; i < strs.length; i++)
    {
        let current = strs[i];
        let values: string[] = [];
        let sorted: string = strs[i].split('').sort().join('');
        let in_hash = hash.has(sorted);
        if(in_hash)
            values = hash.get(sorted);
        if(!in_hash)
            values = [];
        values.push(current);
        hash.set(sorted, values);
    }
    hash.forEach((value, key)=>{
        result.push(value);
    })
    return result;
};
