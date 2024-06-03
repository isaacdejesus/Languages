const triplet_sum_close_target = (arr: number[], target_sum: number) =>
{
    arr.sort((a, b) => a - b);
    let smallest_dif = Infinity;
    for(let i = 0; i < arr.length - 2; i++)
    {
        let left = i + 1;
        let right = arr.length - 1;
        while(left < right)
        {
            const target_dif = target_sum - arr[i] - arr[left] - arr[right];
            if(target_dif === 0)
                return target_sum - target_dif;
            if(Math.abs(target_dif) < Math.abs(smallest_dif))
                smallest_dif = target_dif;
            if(Math.abs(target_dif) < Math.abs(smallest_dif) || 
                (Math.abs(target_dif) === Math.abs(smallest_dif) && target_dif > smallest_dif))
                smallest_dif = target_dif;
            if(target_dif > 0)
                left++;
            else
                right--;
        }
    }
    return target_sum - smallest_dif;
}
console.log(triplet_sum_close_target([-2, 0, 1, 2], 2));
console.log(triplet_sum_close_target([-3, -1, 1, 2], 1));
console.log(triplet_sum_close_target([1, 0, 1, 1], 100));
