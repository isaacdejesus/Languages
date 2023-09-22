const twoSum2 = (numbers: number[], target: number): number[] =>{
    let left = 0;
    let right = numbers.length - 1;
    while(left < right)
    {
        let current_sum = numbers[left] + numbers[right];
        if(current_sum > target)
            right--;
        else if(current_sum < target)
            left++;
        else
            return [left + 1, right + 1]
    }
    return [];
};