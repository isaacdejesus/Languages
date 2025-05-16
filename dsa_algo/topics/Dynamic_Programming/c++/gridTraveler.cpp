#include<iostream>
#include<unordered_map>

int gridTraveler(int, int);
int gridTravelerMemoized(int, int, std::unordered_map<std::string, int>);
int main()
{
    std::cout<<gridTraveler(2,3)<<'\n';
    std::unordered_map<std::string, int> cache;
    std::cout<<gridTravelerMemoized(2,3, cache)<<'\n';
    return 0;
}
int gridTraveler(int m , int n)
{
    if(m == 1 && n == 1)
        return 1;
    if(m == 0 || n == 0)
        return 0;
    return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}


int gridTravelerMemoized(int m , int n, std::unordered_map<std::string, int> cache)
{
    std::string key = std::to_string(m) + ',' + std::to_string(n);
    if(cache[key])
        return cache[key];
    if(m == 1 && n == 1)
        return 1;
    if(m == 0 || n == 0)
        return 0;
    cache[key] = gridTravelerMemoized(m - 1, n, cache) + gridTravelerMemoized(m, n - 1, cache);
    return cache[key];
}
