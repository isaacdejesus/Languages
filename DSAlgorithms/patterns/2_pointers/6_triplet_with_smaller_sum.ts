const triplet_smaller_sum = (arr: number[], target: number) => 
{
    arr.sort((a, b) => a - b);
    const triplets: number[] = [];
    for(let i = 0; i < arr.length - 2; i++)
        search_pair(arr, target - arr[i], i, triplets);
    return triplets;
}

const search_pair = (arr: number[], target_sum: number, first: number, triplets: any) =>
{
    let left = first + 1;
    let right = arr.length - 1;
    while(left < right)
    {
        if(arr[left] + arr[right] < target_sum)
        {
            for(let i = right; i > left; i--)
                triplets.push([arr[first], arr[left], arr[i]])
            left++;
        }
        else
            right--;
    }
}

console.log(triplet_smaller_sum([-1, 0, 2, 3], 3));
console.log(triplet_smaller_sum([-1, 4, 2, 1, 3], 5));
