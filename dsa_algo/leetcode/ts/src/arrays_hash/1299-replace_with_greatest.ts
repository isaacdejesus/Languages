const replaceElements = (arr: number[]): number[] => {
    let current_max = -1;
    for(let i = arr.length - 1; i >= 0; i --)
    {
        let new_max = Math.max(current_max, arr[i]);
        arr[i] = current_max;
        current_max = new_max;
    }
    return arr;
};
