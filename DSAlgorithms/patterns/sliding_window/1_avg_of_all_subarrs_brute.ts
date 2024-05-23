const find_avgs_of_subarrs = (k:number, arr: number[]) => {
    const result: number[] = [];
    for(let i = 0; i < arr.length - k + 1; i++)
    {
        let sum = 0;
        for(let j = i; j < i + k; j++)
            sum += arr[j];
        result.push(sum / k);
    }
    return result;
}

const result = find_avgs_of_subarrs(5, [1, 3, 2, 6, -1, 4, 1, 8, 2]);
console.log(`avg of subarrays of size k: ${result}`);
