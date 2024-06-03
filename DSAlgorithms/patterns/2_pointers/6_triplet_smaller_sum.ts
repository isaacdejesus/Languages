const triplet_smaller_sum = (arr: number[], target: number) => 
{
    arr.sort((a, b) => a - b);
    let count = 0;
    for(let i = 0; i < arr.length - 2; i++)
        count += search_pair(arr, target - arr[i], i);
    return count;
}

const search_pair = (arr: number[], target_sum: number, first: number) =>
{
    let count = 0;
    let left = first + 1;
    let right = arr.length - 1;
    while(left < right)
    {
        if(arr[left] + arr[right] < target_sum)
        {
            count += right - left;
            left++;
        }
        else
            right--;
    }
    return count;
}

console.log(triplet_smaller_sum([-1, 0, 2, 3], 3));
console.log(triplet_smaller_sum([-1, 4, 2, 1, 3], 5));
