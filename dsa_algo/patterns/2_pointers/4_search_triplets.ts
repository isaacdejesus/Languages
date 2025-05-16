const search_triplets = (arr:number[]) =>
{
    arr.sort((a, b) => a - b);
    const triplets: number[] = [];
    for(let i = 0; i < arr.length; i++)
    {
        if(i > 0 && arr[i] === arr[i - 1])
            continue;
        search_pair(arr, -arr[i], i + 1, triplets);
    }
    return triplets;
}
const search_pair = (arr: number[], target_sum: number, left: number, triplets:any) => 
{
    let right = arr.length - 1;
    while(left < right)
    {
        const current_sum = arr[left] + arr[right];
        if(current_sum === target_sum)
        {
            triplets.push([-target_sum, arr[left], arr[right]]);
            left++;
            right--;
            while(left < right && arr[left] === arr[left - 1])
                left++;
            while(left < right && arr[right] === arr[right + 1])
                right --;
        }
        else if(target_sum > current_sum)
            left++;
        else
            right--;
    }
}
console.log(search_triplets([-3, 0, 1, 2, -1, 1, -2]));
console.log(search_triplets([-5, 2, -1, -2, 3]));
