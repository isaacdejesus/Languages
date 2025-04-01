class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int left = 1;
       int right = 0;
       for(int i = 0; i < piles.size(); i ++)
            right = std::max(right, piles[i]);
        int result = right;
        while(left <= right)
        {
            int k = left + (right - left)/2;
            long hours = 0;
            for(int i = 0; i < piles.size(); i++)
                hours += ceil((double)piles[i]/k);
            if(hours <= h)
            {
                result = std::min(result, k);
                right = k - 1;
            }
            else
                left = k + 1;
        }
        return result;

    }
};