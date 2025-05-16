const shortest_window_sort = (arr: number[]) => {
    let low = 0;
    let high = arr.length - 1;
    while((low < arr.length - 1 && arr[low] <= arr[low + 1]))
        low++;
    if(low === arr.length - 1)
        return 0;
    while(high > 0 && arr[high] >= arr[high - 1])
        high--;
    let subarr_max = -Infinity;
    let subarr_min = Infinity;
    for(let k = low; k < high + 1; k++)
    {
        subarr_max = Math.max(subarr_max, arr[k]);
        subarr_min = Math.min(subarr_min, arr[k]);
    }
    while(low > 0 && arr[low - 1] > subarr_min)
        low--;
    while(high < arr.length - 1 && arr[high + 1] < subarr_max)
        high++;
    return high - low + 1;
}

console.log(shortest_window_sort([1, 2, 5, 3, 7, 10, 9, 12]));
console.log(shortest_window_sort([1, 3, 2, 0, -1, 7, 10]));
console.log(shortest_window_sort([1, 2, 3]));
console.log(shortest_window_sort([3, 2, 1]));
