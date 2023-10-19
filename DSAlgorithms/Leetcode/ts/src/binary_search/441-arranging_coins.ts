const arrangeCoins = (n: number): number =>{
    let left = 1;
    let right = n
    let result = 0;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) /2);
        let needed = (mid / 2) * (mid + 1);
        if(needed > n)
            right = mid - 1;
        else 
        {
            left = mid + 1;
            result = Math.max(result, mid)
        }
    }
    return result;
};