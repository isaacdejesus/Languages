class Solution {
public:
    int arrangeCoins(int n) {
       int left = 1;
       int right = n;
       int result = 0;
       while(left <= right) 
       {
           int mid = left + (right - left) / 2;
           long long needed = (double)mid * (mid + 1) /2;
           if(needed > n)
                right = mid - 1;
           else
           {
               left = mid + 1;
               result = std::max(result, mid);
           }
       }
       return result;
    }
};