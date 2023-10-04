const numOfSubarrays = (arr: number[], k: number, threshold: number): number =>{
    let result = 0;
    let current_sum = 0;
    for(let i = 0; i < k - 1; i++)
        current_sum += arr[i];
    for(let left = 0; left < arr.length - k + 1; left ++)
    {
        current_sum += arr[left + k - 1];
        if((current_sum / k) >= threshold)
            result++;
        current_sum -= arr[left];
    }
    return result;



};