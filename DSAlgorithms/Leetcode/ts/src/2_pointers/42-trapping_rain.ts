const trap  = (height: number[]): number  =>{
    if(height.length === 0)
        return 0;

    let left = 0;
    let right = height.length - 1;
    let left_max = height[left];
    let right_max = height[right];
    let sum = 0;
    while(left < right)
    {
        if(left_max < right_max)
        {
            left++;
            left_max = Math.max(left_max, height[left]);
            sum += left_max - height[left];
        }
        else
        {
            right--;
            right_max = Math.max(right_max, height[right]);
            sum += right_max - height[right];
        }
    }
    return sum;

};