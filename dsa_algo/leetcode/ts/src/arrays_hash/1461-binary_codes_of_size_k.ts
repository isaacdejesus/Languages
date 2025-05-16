const hasAllCodes =(s: string, k: number): boolean =>{
    const a_set = new Set<string>();
    if(k > s.length)
        return false;
    for(let i = 0; i < (s.length - k + 1); i++)
        a_set.add(s.substr(i, k));

    return (a_set.size === (1 << k));

};
