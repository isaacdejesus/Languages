class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int result = 0;
       int current_sum = 0;
       for(int i = 0; i < k - 1; i++)
            current_sum += arr[i];
       for(int left = 0; left < arr.size() - k + 1; left++) 
       {
           current_sum += arr[left + k - 1];
           if((current_sum / k) >= threshold)
                result++;
            current_sum -= arr[left];
       }
       return result;
    }
};