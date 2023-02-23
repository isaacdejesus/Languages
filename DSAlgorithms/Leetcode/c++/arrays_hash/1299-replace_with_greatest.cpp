class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int right_max = -1;
       for(int i = arr.size() - 1; i >= 0; i--)
       {
           int new_max = std::max(right_max, arr[i]);
           arr[i] = right_max;
           right_max = new_max;
       } 
       return arr;
    }