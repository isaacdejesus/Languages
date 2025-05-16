const isIsomorphic = (s: string, t: string): boolean =>{
    const s_map = new Map<string, string>();
    const t_map = new Map<string, string>();    
    for(let i = 0; i < s.length; i++)
    {
        const c1: string = s[i];
        const c2: string= t[i];
        if((s_map.has(c1) && s_map.get(c1) !== c2) || (t_map.has(c2) && t_map.get(c2) !== c1))
            return false;
        s_map.set(c1, c2);
        t_map.set(c2, c1);
    }
    return true;
};
