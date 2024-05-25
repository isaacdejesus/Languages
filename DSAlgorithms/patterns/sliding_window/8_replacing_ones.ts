const longest_substring = (arr: number[], k: number) =>
{
    let window_start = 0;
    let max_length = 0;
    let max_ones_count = 0;
    for(let window_end = 0; window_end < arr.length; window_end++)
    {
        if(arr[window_end] === 1)
            max_ones_count ++;
        if((window_end - window_start + 1 - max_ones_count) > k)
        {
            if(arr[window_start] === 1)
                max_ones_count -= 1;
            window_start += 1;
        }
        max_length = Math.max(max_length, window_end - window_start + 1);
    }
    return max_length;
}

console.log(longest_substring([0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], 2));
console.log(longest_substring([0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1 ], 3));
