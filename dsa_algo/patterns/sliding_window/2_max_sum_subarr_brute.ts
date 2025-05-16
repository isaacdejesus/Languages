const max_sum_subarr = (k: number, arr: number[]) => {
    let max_sum = 0;
    let window_sum = 0;
    for(let i = 0; i < arr.length - k + 1; i++)
    {
        window_sum = 0;
        for(let j = i; j < i + k; j++)
            window_sum += arr[j];
        max_sum = Math.max(max_sum, window_sum);
    }
    return max_sum;
}
console.log(`maximun sum of a subarray of size k: ${max_sum_subarr(3, [2, 1, 5, 1, 3, 2])}`);
console.log(`maximun sum of a subarray of size k: ${max_sum_subarr(2, [2, 3, 4, 1, 5])}`);
