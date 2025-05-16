const find_substring = (str: string, pattern: string) => {
    let window_start = 0;
    let matched = 0;
    let substr_start = 0;
    let min_length = str.length + 1;
    const char_freq = new Map<string, number>();
    for(let i = 0; i < pattern.length; i++)
    {
        const chr = pattern[i];
        if(!char_freq.has(chr))
            char_freq.set(chr, 1);
        else{
            const current = char_freq.get(chr);
            if(current !== undefined)
                char_freq.set(chr, current + 1);
        }
    }
    for(let window_end = 0; window_end < str.length; window_end++)
    {
        const right_char = str[window_end];
        if(char_freq.has(right_char))
        {
            let current = char_freq.get(right_char);
            if(current !== undefined)
                char_freq.set(right_char, current - 1);
            current = char_freq.get(right_char);
            if(current !== undefined && current >= 0)
                matched ++;
        }
        while(matched === pattern.length)
        {
            if(min_length > window_end - window_start + 1)
            {
                min_length = window_end - window_start + 1;
                substr_start = window_start;
            }

            const left_char = str[window_start];
            window_start += 1;
            if(char_freq.has(left_char))
            {
                let current = char_freq.get(left_char);
                if(current !== undefined && current === 0)
                {
                    matched--;
                }

                current = char_freq.get(left_char);
                if(current !== undefined)
                    char_freq.set(left_char, current + 1);
            }
        }
    }
        if(min_length > str.length)
            return '';
        return str.substring(substr_start, substr_start + min_length);
}
console.log(find_substring('aabdec', 'abc'));
console.log(find_substring('abdabca', 'abc'));
console.log(find_substring('adcad', 'abc'));
