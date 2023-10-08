class MinStack {
    std::stack<int> a_stack;
    std::stack<int> min_stack;
public:
    MinStack() {
       a_stack = {};
       min_stack = {};
    }
    
    void push(int val) {
        a_stack.push(val);
        int new_min = 0;
        if(!min_stack.empty())
            new_min = std::min(val, min_stack.top());
        else new_min = val;
        min_stack.push(new_min);
    }
    
    void pop() {
       a_stack.pop();
       min_stack.pop();
    }
    
    int top() {
       return a_stack.top();
    }
    
    int getMin() {
       return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */