#include<iostream>
#include<unordered_map>
#include<stack>
bool isValid(std::string);
int main()
{
    std::cout<<isValid("[({})]")<<'\n';
    std::cout<<isValid("[({)]")<<'\n';
    return 0;
}

bool isValid(std::string s)
{
    std::unordered_map<char, char> hash = {{'{','}'}, {'(',')'}, {'[',']'}};
    std::stack<char> char_stack;
    int string_size = s.length();
    for(int character = 0; character < string_size; character++)
    {
        if(hash.count(s[character]))
            char_stack.push(s[character]);
        else{
            if(char_stack.empty())
                return false;
            char current_char = char_stack.top();
            char_stack.pop();
            if(hash[current_char] != s[character])
                return false;
        }
    }
        return char_stack.empty();
}
