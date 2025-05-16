const minFlips = (s: string): number =>{
    const window_size = s.length;
    s = s + s;
    let alt_string1 = "";
    let alt_string2 = "";
    for(let i = 0; i < s.length; i++)
    {
        if(i % 2 === 0)
        {
            alt_string1 += '0';
            alt_string2 += '1';
        }
        else
        {
            alt_string1 += '1';
            alt_string2 += '0';
        }
    }
    let result = s.length;
    let diff1 = 0;
    let diff2 = 0;
    let left = 0;
    for(let right = 0; right < s.length; right++)
    {
        if(s[right] !== alt_string1[right])
            diff1++;
        if(s[right] !== alt_string2[right])
            diff2++;
        if((right - left + 1) > window_size)
        {
            if(s[left] !== alt_string1[left])
                diff1--;
            if(s[left] !== alt_string2[left])
                diff2--;
            left++;
        }
        if((right - left + 1) === window_size)
            result = Math.min(result, diff1, diff2);
    }
    return result;
};