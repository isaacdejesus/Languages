const mySqrt = (x: number): number =>{
    let left = 0;
    let right = x;
    let result = 0;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) /2);
        if((mid * mid) > x)
            right = mid - 1;
        else if((mid * mid) < x)
        {
            left = mid + 1;
            result = mid;
        }
        else
            return mid;
    }
    return result;
};