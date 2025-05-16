class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> hash = {{'{','}'}, {'(',')'}, {'[',']'}};
        std::stack<char> a_stack;
        for(int i = 0; i < s.length(); i++){
            if(hash.count(s[i]))
                a_stack.push(s[i]);
            else
            {
                if(a_stack.empty())
                    return false;
                char c = a_stack.top();
                a_stack.pop();
                if(hash[c] != s[i])
                    return false;
            }
        }
        return a_stack.empty();
    }
};