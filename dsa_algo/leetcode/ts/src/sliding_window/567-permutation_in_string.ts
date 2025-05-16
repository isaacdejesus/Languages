const checkInclusion  = (s1: string, s2: string): boolean =>{
    if(s1.length > s2.length)
        return false;
    const s1_count: number[] = new Array(26).fill(0);
    const s2_count: number[] = new Array(26).fill(0);
    for(let i = 0; i < s1.length; i++)
    {
        const char_a = 'a';
       s1_count[s1.charCodeAt(i) - char_a.charCodeAt(0)]++;
       s2_count[s2.charCodeAt(i) - char_a.charCodeAt(0)]++;
    }
    let matches = 0;
    for(let i = 0; i < 26; i++)
    {
        if(s1_count[i] === s2_count[i])
            matches++;

    }
    let left = 0;
    for(let right = s1.length; right < s2.length; right++)
    {
        if(matches === 26)
            return true;
        let char_a = 'a';
        let index = s2.charCodeAt(right) - char_a.charCodeAt(0);
        s2_count[index]++;
        if(s1_count[index] === s2_count[index])
            matches++;
        else if(s1_count[index] + 1 === s2_count[index])
            matches--;

        index = s2.charCodeAt(left) - char_a.charCodeAt(0);
        s2_count[index]--;
        if(s1_count[index] === s2_count[index])
            matches++;
        else if(s1_count[index] - 1 === s2_count[index])
            matches--;
        left++;
    }
    console.log(matches)
    return matches === 26;
};