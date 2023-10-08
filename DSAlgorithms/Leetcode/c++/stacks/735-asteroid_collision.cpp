class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       std::stack<int> a_stack; 
       for(int i = 0; i < asteroids.size(); i++)
       {
           while(!a_stack.empty() && asteroids[i] < 0 && a_stack.top() > 0)
           {
               int diff = asteroids[i] + a_stack.top();
               if(diff < 0)
                    a_stack.pop();
                else if(diff > 0)
                    asteroids[i] = 0;
                else
                {
                    asteroids[i] = 0;
                    a_stack.pop();
                }
           }
           if(asteroids[i] != 0)
               a_stack.push(asteroids[i]);
       }
       std::vector<int> result;
       while(!a_stack.empty())
        {
            result.push_back(a_stack.top());
            a_stack.pop();
        }
        reverse(result.begin(), result.end());
       return result;
    }
};