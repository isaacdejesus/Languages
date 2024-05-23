const fibonacci = (n: number): number => {
    if(n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

const fibonacciMemoized = (n: number): number => {
    const cache = new Map<number, number>();
    const inCache = cache.get(n);
    if(inCache)
        return inCache;
    if(n <= 2)
        return 1;
    cache.set(n, fibonacciMemoized(n - 1) + fibonacciMemoized(n - 2));
    let currentFib: number = 0;
    const getCurrentfib = cache.get(n);
    if(getCurrentfib)
        currentFib = getCurrentfib;
    return currentFib;
}

console.log(fibonacci(6));
console.log(fibonacciMemoized(6));
