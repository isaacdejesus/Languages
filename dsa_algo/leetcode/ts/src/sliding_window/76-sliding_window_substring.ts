const minWindow = (s: string, t: string): string =>{
    if(t == "")
        return "";
    const t_hash = new Map<string, number>();
    const window = new Map<string, number>();
    for(let i = 0; i < t.length; i++)
    {
        if(t_hash.has(t[i]))
        {
            let current = t_hash.get(t[i]);
            t_hash.set(t[i], current + 1);
        }
        else
            t_hash.set(t[i], 1);
    }
    let have = 0;
    let need = t_hash.size;
    const result: number[] = [];
    result[0] = -1;
    result[1] = -1;
    let result_length = Infinity;
    let left = 0;
    for(let right = 0; right < s.length; right++)
    {
        let c = s[right];
        if(window.has(c))
        {
            let current = window.get(c);
            window.set(c, current + 1);
        }
        else
            window.set(c, 1);

        if(t_hash.has(c) && window.get(c) === t_hash.get(c))
            have++;

        while(have === need)
        {
            if((right - left + 1) < result_length)
            {
                result[0] = left;
                result[1] = right;
                result_length = (right - left + 1);
            }
            if(window.has(s[left]))
            {
                let current = window.get(s[left]);
                window.set(s[left], current - 1);
            }
            if(t_hash.has(s[left]) && window.get(s[left]) < t_hash.get(s[left]))
            {
                have-= 1;
                console.log("decreasing have", have);
            }
            left++;
        }
    }
    if(result_length !== Infinity)
        return s.substr(result[0] , result[1] - result[0] + 1);
    return "";
};