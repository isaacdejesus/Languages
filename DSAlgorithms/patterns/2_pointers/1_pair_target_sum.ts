const pair_target_sum = (arr: number[], target_sum: number) => {
    let left = 0;
    let right = arr.length - 1;
    while(left < right)
    {
        const current_sum = arr[left] + arr[right];
        if(current_sum == target_sum)
            return [left, right];
        if(target_sum > current_sum)
            left++;
        else 
            right--;
    }
    return [-1, -1];
}
console.log(pair_target_sum([1, 2, 3, 4, 6], 6));
console.log(pair_target_sum([2, 5, 9, 11], 11));
