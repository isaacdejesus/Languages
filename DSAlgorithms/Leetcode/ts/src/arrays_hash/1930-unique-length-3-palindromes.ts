const countPalindromicSubsequence = (s: string): number =>{
    const right = new Map<string, number>();
    const left = new Set<string>();
    const result: { [string: string]: string} = {};
    for(let i = 0; i < s.length; i++)
    {
        if(right.has(s[i]))
        {
            const current_val = right.get(s[i]);
            right.set(s[i], current_val + 1);
        }
        else
            right.set(s[i], 1);
    }
    for(let i = 0; i < s.length; i++)
    {
        if(right.has(s[i]))
        {
            const current_val = right.get(s[i]);
            right.set(s[i], current_val - 1);
        }
        if(right.has(s[i]) && right.get(s[i]) === 0)
            right.delete(s[i]);
        for(let j = 0; j < 26; j++)
        {
            const c: string = String.fromCharCode(97 + j);
            if(left.has(c) && right.has(c))
            {
                let temp: string = c;
                let final_temp: string = c + s[i];
                if(!result[final_temp])
                    result[final_temp] = c;
            }
        }
        left.add(s[i]);
    }
    const arr = Object.keys(result);
    return arr.length;

};