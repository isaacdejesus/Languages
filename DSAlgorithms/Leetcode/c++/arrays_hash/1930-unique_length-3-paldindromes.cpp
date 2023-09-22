class Solution {
public:
    int countPalindromicSubsequence(string s) {
       std::unordered_map<char, int> right;
       std::unordered_multimap<std::string, char> result;
       std::set<char> left;
       for(int i = 0; i < s.size(); i++)
            right[s[i]]++;

       for(int i = 0; i < s.size(); i++)
       {
           if(right.count(s[i]) > 0)
           {
               //std::cout<<s[i]<<" count is "<<right[s[i]]<<" decreasing by 1"<<'\n';
                right[s[i]]--;
            if(right.count(s[i]) > 0 && right[s[i]] == 0)
            {
                //std::cout<<s[i]<<" ";
                //std::cout<<" count is 0, deleting from hash"<<'\n';
                right.erase(s[i]);
            }

           }
            
            for(int j = 0; j < 26; j++)
            {
                char c = 'a' + j;
                //std::cout<<"c is: "<<c<<'\n';
                if(left.count(c) > 0 && right.count(c) > 0)
                {
                    //std::cout<<c<<" is in both left and right. mapping "<<s[i]<<" to "<<c<<'\n';
                    std::string temp = "";
                    temp+=c;
                    temp+=s[i];
                    if(!(result.count(temp) > 0))
                        result.insert({{temp, c}});
                    //std::cout<<"Current result size is: "<<result.size()<<'\n';
                }
            }
            //std::cout<<"Adding "<<s[i]<<" to left set"<<'\n';
            left.insert(s[i]);
       }
       return result.size();
    }
};