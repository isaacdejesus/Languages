class Solution {
public:
    static bool compare(std::string a, std::string b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> vec;
        std::string result = "";
        for(int i = 0; i < nums.size(); i++)
            vec.push_back(std::to_string(nums[i]));
        std::sort(vec.begin(), vec.end(), compare);
       if(vec[0] == "0")
            return "0";
        for(auto val: vec)
           result += val; 
        
        return result;
    }
};