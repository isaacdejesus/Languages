class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       std::unordered_set<std::string> a_set;
       std::unordered_set<std::string> answer_set;
       std::vector<std::string> result;
       int s_size = s.size();
       for(int left = 0; left < (s_size - 9); left++)
       {
           std::string current = s.substr(left, 10);
           std::unordered_set<std::string>::iterator find_iterator = a_set.find(current);
           if(find_iterator != a_set.end())
                answer_set.insert(current);
            a_set.insert(current);
       }
       for(auto item: answer_set)
            result.push_back(item);
        return result;
    }
};