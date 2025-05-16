#include <iostream>
#include <stack>

int min_add_make_valid_parenthesis(std::string);
int main()
{
    std::string s = "()))";
    std::cout<<min_add_make_valid_parenthesis(s);
    return 0;
}
int min_add_make_valid_parenthesis(std::string s)
{
    std::stack<char> st;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] == ')')
        {
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(s[i]);
        }
        else
            st.push(s[i]);
    }
    return st.size();
}