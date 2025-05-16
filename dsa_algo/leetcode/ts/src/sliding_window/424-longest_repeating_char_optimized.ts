const characterReplacement = (s: string, k: number): number =>{
    //optimized
    const count_hash = new Map<string, number>();
    let result = 0;
    let left = 0;
    let max_char = 0;
    for(let right = 0; right < s.length; right++)
    {
        if(count_hash.has(s[right]))
        {
            const current = count_hash.get(s[right]);
            count_hash.set(s[right], current + 1);
        }
        else
            count_hash.set(s[right], 1);
        max_char = Math.max(max_char, count_hash.get(s[right]));
        //count_hash.forEach((value, key) => {
            //max_char = Math.max(max_char, value);
        //}) 
        while(((right - left + 1) - max_char)> k)   
        {
            if(count_hash.has(s[left]))
            {
                const current = count_hash.get(s[left]);
                count_hash.set(s[left], current - 1);
            }
           left++; 
        //count_hash.forEach((value, key) => {
            //max_char = Math.max(max_char, value);
        //}) 
        }
        result = Math.max(result, right - left + 1);
    }
    return result;

};