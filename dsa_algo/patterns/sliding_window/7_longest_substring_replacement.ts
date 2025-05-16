const length_of_longest_substring = (str: string, k: number) =>
{
    let window_start = 0;
    let max_length = 0;
    let max_repeat_letter_count = 0;
    const frequency_map = new Map<string, number>();
    for(let window_end = 0; window_end < str.length; window_end++)
    {
        const right_char = str[window_end];
        if(!frequency_map.has(right_char))
            frequency_map.set(right_char, 0);
        let current = frequency_map.get(right_char);
        if(current !== undefined)
        {
            frequency_map.set(right_char, current + 1);
        }
        current = frequency_map.get(right_char);
        if(current !== undefined)
            max_repeat_letter_count = Math.max(max_repeat_letter_count, current);
        if((window_end - window_start + 1 - max_repeat_letter_count) > k)
        {
            const left_char = str[window_start];
            const current = frequency_map.get(left_char);
            if(current !== undefined)
                frequency_map.set(left_char, current - 1);
            window_start++;
        }
        max_length = Math.max(max_length, window_end - window_start + 1);
    }
    return max_length;
}
console.log(length_of_longest_substring('aabccbb', 2));
console.log(length_of_longest_substring('abbcb', 1));
console.log(length_of_longest_substring('abccde', 1));
