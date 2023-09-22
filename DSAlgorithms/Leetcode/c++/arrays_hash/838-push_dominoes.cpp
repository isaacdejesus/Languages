class Solution {
public:
    string pushDominoes(string dominoes) {
        std::vector<char> doms;
        std::queue<std::string> q;  //[0] is char and rest is index
        std::string result = "";
        for(int i = 0; i < dominoes.size(); i++)
            doms.push_back(dominoes[i]);
        for(int i = 0; i < doms.size(); i++)
        {
            if(doms[i] != '.')
            {
                std::string val ="";
                val+=doms[i];
                val+= to_string(i);
                q.push(val);
            }
        }
       while(!q.empty()) 
       {
          std::string current = q.front();
          q.pop();
          char current_char = current[0];
          current = current.substr(1);
          int index = std::stoi(current);
          if(current_char == 'L')
          {
                if(index > 0 && doms[index - 1] == '.')
                {
                    int i = index;
                    i--;
                    q.push("L" + to_string(i));
                    doms[index - 1] = 'L';
                }
          }
          else if(current_char == 'R')
          {
              if(index  + 1 < doms.size() && doms[index + 1] == '.')              
              {
                  if(index + 2 < doms.size() && doms[index + 2] == 'L')
                    {
                        q.pop();
                    }
                    else
                    {
                        q.push("R" + to_string(index + 1));
                        doms[index + 1] = 'R';
                    }
              }
          }

       }
       for(int i = 0; i < doms.size(); i++)
            result+= doms[i];
       return result;
    }
};