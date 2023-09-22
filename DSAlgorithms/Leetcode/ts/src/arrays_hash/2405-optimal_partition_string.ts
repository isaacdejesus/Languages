const partitionString = (s: string): number =>{
    const current_set = new Set<string>();
    let result = 1;
    for(let i = 0; i < s.length; i++)
    {
        if(current_set.has(s[i]))
        {
            result++;
            current_set.clear();
        }
        current_set.add(s[i]);
    }
    return result;
};