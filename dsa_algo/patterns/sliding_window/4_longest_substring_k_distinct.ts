const longest_substring_k_distinct = (str: string, k: number) =>
{
    let window_start = 0;
    let max_length = 0;
    let char_frequency = new Map<string, number>();
    for(let window_end = 0; window_end < str.length; window_end++)
    {
        const right_char = str[window_end];
        if(!char_frequency.has(right_char))
            char_frequency.set(right_char, 0);
        else
        {
            const current = char_frequency.get(right_char);
            if(current !== undefined)
                char_frequency.set(right_char, current + 1);
        }
        while(char_frequency.size > k)
        {
            const left_char = str[window_start];
            if(char_frequency.has(left_char) && char_frequency.get(left_char) === 0)
                char_frequency.delete(left_char);
            if(char_frequency.has(left_char))
            {
                const current = char_frequency.get(left_char);
                if(current)
                    char_frequency.set(left_char, current - 1);
            }
            window_start ++; 
        }
        max_length = Math.max(max_length, window_end - window_start + 1);
    }
    return max_length;
}

console.log(`Length of longest substring: ${longest_substring_k_distinct('araaci', 2)}`);
console.log(`Length of longest substring: ${longest_substring_k_distinct('araaci', 1)}`);
console.log(`Length of longest substring: ${longest_substring_k_distinct('cbbebi', 3)}`);
