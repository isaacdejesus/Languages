#include<bits/stdc++.h>
int count = 0;
void print(int n)
{
    if(count == n)
        return;
    std::cout<<count<<'\n';
    count++;
    print(n);
}
int main()
{
    print(5);
}
