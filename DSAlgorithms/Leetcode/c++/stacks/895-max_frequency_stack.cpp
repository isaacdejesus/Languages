class FreqStack {
public:
    std::unordered_map<int, int> val_count;
    int max_count;
    std::unordered_map<int, std::stack<int>> stacks_hash;
    FreqStack() {
       val_count = {};
       max_count = 0;
       stacks_hash = {};
    }
    
    void push(int val) {
        int current_val_count = 0;
       if(val_count.count(val) > 0) 
           current_val_count = val_count[val] + 1;
        else
            current_val_count = 1;
        val_count[val] = current_val_count;
        if(current_val_count > max_count)
        {
            max_count = current_val_count;
            std:stack<int> temp_stack;
            stacks_hash[current_val_count] = temp_stack;
        }
        std::stack<int> temp_stack = stacks_hash[current_val_count];
        temp_stack.push(val);
        stacks_hash[current_val_count] = temp_stack;
    }
    
    int pop() {
        std::stack<int> temp = stacks_hash[max_count];
        int result = 0;
        if(!temp.empty())
        {
            result = temp.top();
        temp.pop();
        stacks_hash[max_count] = temp;
        val_count[result]--;
        if(temp.empty())
            max_count--;
            }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */