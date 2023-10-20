class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::vector<std::vector<std::string>> result;    
        std::sort(products.begin(), products.end());
        int left = 0;
        int right = products.size() - 1;
        for(int i = 0; i < searchWord.size(); i++)
        {
            char c = searchWord[i];
            while(left <= right && (products[left].size() <= i || products[left][i] != c))
                left++;
            while(left <= right && (products[right].size() <= i || products[right][i] != c))
                right--;
            int remain = right - left + 1;
            int temp = std::min(3, remain);
            std::vector<std::string> t;
            for(int j = left; j < left + temp; j++)
            {
                t.push_back(products[j]);
            }
                result.push_back(t);
        }
        return result;
    }
};