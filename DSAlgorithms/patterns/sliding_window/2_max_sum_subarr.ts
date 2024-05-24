const max_sum_subarr = (k: number, arr: number[]) => {
    let max_sum = 0;
    let window_sum = 0;
    let window_start = 0;
    for(let window_end = 0; window_end < arr.length ; window_end++)
    {
        window_sum += arr[window_end];
        if(window_end >= k - 1)
        {
            max_sum = Math.max(max_sum, window_sum);
            window_sum -= arr[window_start];
            window_start++;
        }
    }
    return max_sum;
}
console.log(`maximun sum of a subarray of size k: ${max_sum_subarr(3, [2, 1, 5, 1, 3, 2])}`);
console.log(`maximun sum of a subarray of size k: ${max_sum_subarr(2, [2, 3, 4, 1, 5])}`);
