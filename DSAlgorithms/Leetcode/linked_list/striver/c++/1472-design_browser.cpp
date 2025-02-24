class ListNodee
{
    public:
        std::string val;
        ListNodee* prev;
        ListNodee* next;
        ListNodee(std::string val_, ListNodee* prev_ = nullptr, ListNodee* next_ = nullptr)
        {
            val = val_;
            prev = prev_;
            next = next_;
        }
};
class BrowserHistory {
public:
    ListNodee* current;
    BrowserHistory(string homepage) {
        ListNodee* new_node = new ListNodee(homepage);
        current = new_node;
    }
    
    void visit(string url) {
       ListNodee* new_node = new ListNodee(url, current);
       current->next = new_node;
       current = new_node;
       
    }
    
    string back(int steps) {
       while(current->prev != nullptr && steps > 0) 
       {
           current = current->prev;
           steps--;
       }
       return current->val;
    }
    
    string forward(int steps) {
       while(current->next != nullptr && steps > 0) 
       {
           current = current->next;
           steps--;
       }
       return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */