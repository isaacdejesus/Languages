const search_quad = (arr: number[], target: number) =>{
    arr.sort((a, b) => a - b);
    const quadruplets: number[][] = [];
    for(let i = 0; i < arr.length - 3; i++)
    {
        if(i > 0 && arr[i] === arr[i - 1])
            continue;
        for(let j = i + 1; j < arr.length - 2; j++)
        {
            if(j > i + 1 && arr[j] === arr[j - 1])
                continue;
            search_pairs(arr, target, i, j, quadruplets);
        }
    }
    return quadruplets;
}

const search_pairs = (arr: number[], target_sum: number, first: number, second: number, quadruplets: number[][]) =>
{
    let left = second + 1;
    let right = arr.length - 1;
    while((left < right))
    {
        let sum = arr[first] + arr[second] + arr[left] + arr[right];
        if(sum === target_sum)
        {
            quadruplets.push([arr[first], arr[second], arr[left], arr[right]]);
            left++;
            right--;
            while((left < right && arr[left] === arr[left - 1]))
                left++;
            while((left < right && arr[right] === arr[right + 1]))
                right--;
        }
        else if(sum < target_sum)
            left++;
        else
            right--;
    }
}
console.log(search_quad([4, 1, 2, -1 , 1, -3], 1));
console.log(search_quad([2, 0, -1, 1, -2, 2], 2));
