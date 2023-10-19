class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(), potions.end());
       std::vector<int > result;
       for(int i = 0; i < spells.size(); i++)
       {
            int left = 0;
            int right = potions.size() - 1;
            int index = potions.size();
            while(left <= right) 
            {
                int mid = left + (right - left) / 2;
                if((double)spells[i] * potions[mid] >= success)
                {
                    right = mid - 1;
                    index = mid;
                }
                else
                    left = mid + 1;
            }
            result.push_back(potions.size() - index);
       }
       return result;
    }
};