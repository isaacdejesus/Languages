const gridTraveler = (m: number, n: number): number => {
    if(m === 1 && n == 1)
        return 1;
    if(m === 0 || n === 0)
        return 0;
    return gridTraveler(m -1, n) + gridTraveler(m, n - 1);
}

const gridTravelerMemoized = (m: number, n: number): number => {
    const cache = new Map<string, number>();
    const key = m + ',' + n;
    const checkKey = cache.get(key);
    if(checkKey)
        return checkKey;
    if(m === 1  && n === 1)
        return 1;
    if(m === 0 || n === 0)
        return 0;
    cache.set(key, gridTravelerMemoized(m - 1, n) + gridTravelerMemoized(m, n - 1));
    let currentVal: number = 0;
    const getCurrentVal = cache.get(key);
    if(getCurrentVal)
        currentVal = getCurrentVal;
    return currentVal;
}

console.log(gridTraveler(2,3));
console.log(gridTravelerMemoized(2,3));
