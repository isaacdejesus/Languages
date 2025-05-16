class StockSpanner {
public:
    std::stack<int> price_stack;
    std::stack<int> span_stack;
    StockSpanner() {
       price_stack ={};
       span_stack = {};
    }
    
    int next(int price) {
       int span = 1;
       while(!price_stack.empty() && price >= price_stack.top()) 
       {
           span += span_stack.top();
           price_stack.pop();
           span_stack.pop();
       }
       price_stack.push(price);
       span_stack.push(span);
       return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */