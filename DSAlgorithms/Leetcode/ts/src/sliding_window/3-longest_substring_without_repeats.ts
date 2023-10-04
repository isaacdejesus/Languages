const lengthOfLongestSubstring = (s: string): number =>{
    const a_set = new Set<string>();
    let left = 0;
    let result = 0;
    for(let right = 0; right < s.length; right++)
    {
        while(a_set.has(s[right]))
        {
            a_set.delete(s[left]);
            left++;
        }
        a_set.add(s[right]);
        result = Math.max(result, right - left + 1);
    }
    return result;
};