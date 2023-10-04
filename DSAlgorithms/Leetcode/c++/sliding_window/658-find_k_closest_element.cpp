class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int left = 0;
       int right = arr.size() - k; 
       while(left < right)
       {
           int m = left + (right - left) / 2;
           if((x - arr[m]) > (arr[m + k] - x))
               left = m + 1;
            else
                 right = m;
       }
       std::vector<int> result;
       for(int i = left; i < left + k; i++)
            result.push_back(arr[i]);
       return result;
    }
};