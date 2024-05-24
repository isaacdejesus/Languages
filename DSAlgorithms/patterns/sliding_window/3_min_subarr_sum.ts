const smallest_subarr = (s: number, arr: number[]) => {
    let window_sum = 0;
    let min_length = Infinity;
    let window_start = 0;
    for(let window_end = 0; window_end < arr.length; window_end++)
    {
        window_sum += arr[window_end];
        while(window_sum >= s)
        {
            min_length = Math.min(min_length, window_end - window_start + 1)
            window_sum -= arr[window_start];
            window_start++
        }
    }
    if(min_length === Infinity)
        return 0;
    return min_length;
}

console.log(`Smallest subarray length: ${smallest_subarr(7, [2, 1, 5, 2, 3, 2])}`);
console.log(`Smallest subarray length: ${smallest_subarr(7, [2, 1, 5, 2, 8])}`);
console.log(`Smallest subarray length: ${smallest_subarr(8, [3, 4, 1, 1, 6])}`);
