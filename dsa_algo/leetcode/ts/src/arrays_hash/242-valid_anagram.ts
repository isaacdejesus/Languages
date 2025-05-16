const isAnagram = (s: string, t: string): boolean =>{
    if(s.length !== t.length)
        return false;
    const s_hash = new Map<string, number>();
    const t_hash = new Map<string, number>();
    for(let i = 0; i < s.length; i++) 
    {
        if(s_hash.has(s[i]))
        {
            const current_val = s_hash.get(s[i]);
            s_hash.set(s[i], current_val + 1);
        }
        else 
            s_hash.set(s[i], 1);
    }
    for(let i = 0; i < t.length; i++) 
    {
        if(t_hash.has(t[i]))
        {
            const current_val = t_hash.get(t[i]);
            t_hash.set(t[i], current_val + 1);
        }
        else 
            t_hash.set(t[i], 1);
    }
    let return_value = true;
    s_hash.forEach((value, key) => {
        const t_val = t_hash.get(key);
        if(t_val !== value)
            return_value = false;
    })
    return return_value;
};
