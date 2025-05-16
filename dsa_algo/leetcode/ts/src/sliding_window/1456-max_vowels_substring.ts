const maxVowels = (s: string, k: number): number =>{
    const vowels = new Set<string>(['a', 'e', 'i', 'o', 'u']);
    let left = 0;
    let result = 0;
    let count = 0;
    for(let right = 0; right < s.length; right++)
    {
        if(vowels.has(s[right]))
            count++;
        if((right - left + 1) > k)
        {
            if(vowels.has(s[left]))
                count--;
            left++;
        }
        result = Math.max(result, count);
    }
    return result;

};