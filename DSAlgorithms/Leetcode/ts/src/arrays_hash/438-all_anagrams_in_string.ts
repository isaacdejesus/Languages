const map_equality = (map1: Map<string, number>, map2: Map<string, number>): boolean => {
    let return_value: boolean = true;
    map1.forEach((value, key) => {
       if(value !== map2.get(key))
            return_value = false;
    })
    return return_value;
}
const findAnagrams = (s: string, p: string): number[] =>{
    const result: number[] = [];
    if(p.length > s.length)
        return result;
    const p_hash = new Map<string, number>();
    const s_hash = new Map<string, number>();
    for(let i = 0; i < p.length; i++)
    {
        if(p_hash.has(p[i]))
        {
            const current_val: number = p_hash.get(p[i]);
            p_hash.set(p[i], current_val + 1);
        }
        else 
            p_hash.set(p[i], 1);
        if(s_hash.has(s[i]))
        {
            const current_val: number = s_hash.get(s[i]);
            s_hash.set(s[i], current_val + 1);
        }
        else 
            s_hash.set(s[i], 1);
    }
    if(map_equality(s_hash, p_hash))
    {
        console.log("they are eq");
        result.push(0);
    }
    let left: number = 0;
    for(let right = p.length; right < s.length; right++)
    {
        if(s_hash.has(s[right]))
        {
            const current_val: number = s_hash.get(s[right]);
            s_hash.set(s[right], current_val + 1);
        }
        else 
            s_hash.set(s[right], 1);

        if(s_hash.has(s[left]))
        {
            const current_val: number = s_hash.get(s[left]);
            s_hash.set(s[left], current_val - 1);
        }
        if(s_hash.get(s[left]) === 0)
            s_hash.delete(s[left]);
        left ++;
        if(map_equality(s_hash, p_hash))
            result.push(left);
    }
    return result;
};