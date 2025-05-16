const non_repeat_substring = (str: string)=> {
    let window_start = 0;
    let max_length = 0
    let char_index_max = new Map<string, number>();
    for(let window_end = 0; window_end < str.length; window_end++)
    {
        const right_char = str[window_end];
        if(char_index_max.has(right_char))
        {
            const current = char_index_max.get(right_char);
            if(current !== undefined)
                window_start = Math.max(window_start, current + 1);
        }
        char_index_max.set(right_char, window_end);
        max_length = Math.max(max_length, window_end - window_start + 1);
    }
    return max_length;
}

console.log(`Length of longest substring: ${non_repeat_substring('aabccbb')}`);
console.log(`Length of longest substring: ${non_repeat_substring('abbbb')}`);
console.log(`Length of longest substring: ${non_repeat_substring('abccde')}`);
