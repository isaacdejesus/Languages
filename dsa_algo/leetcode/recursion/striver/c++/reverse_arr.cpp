#include<bits/stdc++.h>
void swap(std::vector<int>& vec, int l, int r)
{
    int temp = vec[l];
    vec[l] = vec[r];
    vec[r] = temp;
}
void f(std::vector<int>& vec, int l, int r)
{
    if(l >= r)
        return;
    swap(vec, l, r);
    f(vec, l + 1, r - 1);
}
void f2(std::vector<int>& vec, int l)
{
    if(l >= vec.size()/2)
        return;
    swap(vec, l, vec.size() - l - 1);
    f2(vec,  l + 1);
}
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 2};
    f(vec, 0, vec.size() - 1);
    for(auto val: vec)
        std::cout<<val<<' ';
    std::cout<<'\n';
    
    vec = {5, 4, 3, 2, 1};
    f2(vec, 0);
    for(auto val: vec)
        std::cout<<val<<' ';
    std::cout<<'\n';
}
