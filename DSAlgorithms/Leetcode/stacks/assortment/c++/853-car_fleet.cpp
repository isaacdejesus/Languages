class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> a_stack;
        std::vector<std::pair<int, double>> pairs;
        for(int i = 0; i < position.size(); i++)
            pairs.push_back({position[i], speed[i]});
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());
        //for(int i = 0; i < pairs.size(); i++)
            //std::cout<<pairs[i].first<<" "<<pairs[i].second<<'\n';
        double temp = (double)(target - pairs[0].first)/ pairs[0].second;
        a_stack.push(temp);
        for(int i = 1; i < pairs.size(); i++)
        {
            //a_stack.push((double)(target - pairs[i].first)/ pairs[i].second);
            temp = (double)(target - pairs[i].first)/ pairs[i].second;
            //double temp = a_stack.top();
            //a_stack.pop();
            //bool should_pop = false;
            if( temp > a_stack.top())
                a_stack.push(temp);
            //if(should_pop == false)
             //   a_stack.push(temp);
        }
        return a_stack.size();
    }
};