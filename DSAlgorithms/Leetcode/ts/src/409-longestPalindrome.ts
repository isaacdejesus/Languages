const longestPalindrome = (s: string): number => {
    let sum = 0;
    const string_size = s.length;
    if(string_size === 0)
        return sum;
    const hash = new Map<string, number>();
    for(let  i = 0; i < string_size; i++)
        {
            if(hash.has(s[i]))
                {
                    let count = hash.get(s[i]);
                    if(count)
                        hash.set(s[i], ++count)
                }
            else
                hash.set(s[i], 1);
        }
    hash.forEach((value:number, key: string) => {
        sum+= Math.floor(value/2) * 2;
    })
    return sum < string_size ? ++sum : sum;
};

console.log(longestPalindrome("abcccdd"));