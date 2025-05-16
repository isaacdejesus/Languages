#include <iostream>

bool isBadVersion(int);
int main()
{
    return 0;
}
int firstBadVersion(int n)
{
    long long int left = 0;
    long long int right = n;

    while(left <= right)
    {
        long long int mid = (left + right) / 2;
        if(isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;
        else if(isBadVersion(mid) && isBadVersion(mid - 1))
            right = mid - 1;
        else if(!isBadVersion(mid))
            left = mid + 1;
    }
    return - 1;
}
