#include <iostream>
#include <unordered_map>

int fibonacci(int n);
int fibonacciMemoized(int n);
int main()
{
    std::cout<<fibonacci(6)<<'\n';
    std::cout<<fibonacciMemoized(6)<<'\n';
    return 0;
}

int fibonacci(int n)
{
    if(n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciMemoized(int n)
{
    std::unordered_map<int, int> cache;
    if(cache[n])
        return cache[n];
    if(n <= 2)
        return 1;
    cache[n] = fibonacciMemoized(n - 1) + fibonacciMemoized(n - 2);
    return cache[n];
}
