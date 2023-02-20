#include<iostream>
#include<stack>
bool is_valid(std::string);
int main()
{
    std::string s =  "({[]})";
    std::cout<<is_valid(s);
    return 0;
}
bool is_valid(std::string s)
{
    std::stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if(s[i] == ')')
                if((st.empty() || st.top() != '('))
                    return false;
            if(s[i] == '}')
                if((st.empty() || st.top() != '{' ))
                    return false;
            if(s[i] == ']')
                if((st.empty() || st.top() != '['))
                    return false;
            st.pop();
        }
    }
    return st.empty();
}