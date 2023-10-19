const can_ship = (mid: number, days: number, weights: number[]): boolean =>{
    let ships = 1;
    let current_cap = mid;
    for(let i = 0; i < weights.length; i++)
    {
        if((current_cap - weights[i] < 0))
        {
            ships++;
            current_cap = mid;
        }
        current_cap -= weights[i];
    }
    return ships <= days;

}
const shipWithinDays = (weights: number[], days: number): number =>{
    let left = 0;
    let right = 0;
    for(let i = 0; i < weights.length; i++)
    {
        left = Math.max(left, weights[i]);
        right += weights[i];
    }
    let result = right;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if(can_ship(mid, days, weights))
        {
            result = Math.min(result, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return result;
};