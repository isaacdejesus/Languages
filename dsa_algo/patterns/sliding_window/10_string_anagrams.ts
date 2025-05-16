const find_string_anagrams = (str: string, pattern: string): number[]=> {
    let window_start = 0;
    let matched = 0;
    let char_freq = new Map<string, number>();
    for(let i = 0; i < pattern.length; i++)
    {
        const chr = pattern[i];
        if(!char_freq.has(chr))
            char_freq.set(chr, 1);
        else
        {
            const current = char_freq.get(chr);
            if(current !== undefined)
                char_freq.set(chr, current + 1);
        }
    }
    const result_indices: number[] = [];
    for(let window_end = 0; window_end < str.length; window_end++)
    {
        const right_char = str[window_end];
        if(char_freq.has(right_char))
        {
            let current = char_freq.get(right_char);
            if(current !== undefined)
                char_freq.set(right_char, current - 1);
            current = char_freq.get(right_char);
            if(current !== undefined && current === 0)
                matched ++;
        }
        if(matched === char_freq.size)
        {
            result_indices.push(window_start);
        }
        if(window_end >= pattern.length - 1)
        {
            const left_char = str[window_start];
            window_start += 1;
            if(char_freq.has(left_char))
            {
                let current = char_freq.get(left_char);
                if(current !== undefined && current === 0)
                    matched -= 1;
                current = char_freq.get(left_char);
                if(current !== undefined)
                    char_freq.set(left_char, current + 1);
            }
        }
    }
    return result_indices;
}
console.log(find_string_anagrams("ppqp", "pq"));
console.log(find_string_anagrams("abbcabc", "abc"));
