class Solution {
public:
    string simplifyPath(string path) {
        std::string result = "";
        path += "/";
        std::string current = "";
        std::stack<std::string> a_stack;
        for(int i = 0; i < path.size(); i++)
        {
            char current_char = path[i];
            if(current_char == '/')
            {
                std::cout<<current<<'\n';
                if(current == "..")
                {
                    if(a_stack.size() > 0)
                        a_stack.pop();
                }
                else if(current != "" && current != ".")
                {
                    a_stack.push(current);
                }
                current = "";
            }
            else
                current += current_char;

            //std::cout<<current<<'\n';
        }
        //std::cout<<a_stack.size();
        while(!a_stack.empty())
        {
           result = "/" + a_stack.top() +  result;
           a_stack.pop();
        }
        if(result == "")
            result = "/";
        return result;
    }
};