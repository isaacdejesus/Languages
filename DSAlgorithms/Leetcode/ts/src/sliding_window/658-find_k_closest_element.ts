const findClosestElements =(arr: number[], k: number, x: number): number[] =>{
    let left = 0;
    let right = arr.length - k;
    while(left < right)
    {
        let m = Math.floor((left + right) / 2);
        if((x - arr[m]) > (arr[m + k] - x))
            left = m + 1;
        else
            right = m;
    }
    const result: number[] = [];
    for(let i = left; i < left + k; i++)
        result.push(arr[i]);
    return result;

};