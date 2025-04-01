class Node
{
    public: 
        int val;
        Node* prev;
        Node* next;

        Node(int val_ = 0, Node* prev_  = nullptr, Node* next_ = nullptr)
        {
            val = val_;
            prev = prev_;
            next = next_;
        }
};
class linked_list
{
    public: 
        Node* left;
        Node* right;
        std::unordered_map<int, Node*> cache;
        linked_list()
        {
            //Node* left = new Node();
            //Node* right = new Node(0, left, nullptr);
            //left->next = right;
            left = nullptr;
            right = nullptr;
            cache = {};
        }
        int length()
        {
            return cache.size();
        }
        void push_right(int val)
        {
                Node* node = new Node();
                node->val = val;
                node->next = nullptr;
                node->prev = nullptr;
                if(left == nullptr && right == nullptr)
                {
                    left = node;
                    right = node;
                }
                else
                {
                    right->next = node;
                    node->prev = right;
                    right = node;
                }
                cache[val] = node;
        }
        void pop(int val)
        {
            if(cache.count(val) < 1)
                return; 
            if(cache.count(val) > 0)
            {
                Node* node = cache[val];
                cache.erase(val);
                //if list is empty
                if(left == nullptr and right == nullptr)
                    return;
                //last node in list
                if(node->next == nullptr && node->prev == nullptr)
                {
                    left = nullptr;
                    right = nullptr;
                    delete node;
                }
                //node is at head
                else if(node->next != nullptr && node->prev == nullptr)
                {
                    node->next->prev = nullptr;
                    left = node->next;
                    delete node;
                }
                //node is at end
                else if(node->next == nullptr && node->prev != nullptr)
                {
                    node->prev->next = nullptr;
                    right = node->prev;
                    delete node;
                }
                //node in between
                else if (node->next != nullptr && node->prev != nullptr)
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    delete node;
                }

                //cache.erase(val);
            }
        }
        int pop_left()
        {
            if(left == nullptr)
                return 0;
            int result = left->val;
            pop(result);
            return result;

        }
        void update(int val)
        {
            pop(val);
            push_right(val);
        }
};

class LFUCache {
private:
    int cap;
    int lfu_count;
    std::unordered_map<int, int> value_map;
    std::unordered_map<int, int> count_map;
    std::unordered_map<int, linked_list*> lists_map;

public:
    LFUCache(int capacity) {
        cap = capacity;
        lfu_count = 0;
        value_map = {};
        count_map = {};
        lists_map = {};
    }
    void counter(int key) 
    {
        linked_list* temp = nullptr;
        int count = count_map[key];
        count_map[key]++;
        if(lists_map.count(count) < 1)
        {
            temp = new linked_list();
            lists_map[count] = temp;
        }
        lists_map[count]->pop(key);
        if(lists_map.count(count + 1) < 1)
        {
            temp = new linked_list();
            lists_map[count + 1] = temp;
        }
        lists_map[count + 1]->push_right(key);
        if(lists_map[count]->length() == 0 && count == lfu_count) 
            lfu_count++;
    }
    int get(int key) {
       if(value_map.count(key) < 1) 
       {
            return -1;
       }
        counter(key);
        return value_map[key];
    }
    
    void put(int key, int value) {
        if(cap == 0) 
            return;
        if(value_map.count(key) < 1 && value_map.size() == cap)
        {
            /*
            std::cout<<value_map.size()<< ": "<<cap<<'\n';
            linked_list* temp = lists_map[lfu_count];
            std::cout<<temp->length()<<'\n';
            Node* temp1 = temp->left;
            while(temp1 != nullptr)
            {
                std::cout<<temp1->val;
                temp1 = temp1->next;
            }
            */
            int result = lists_map[lfu_count]->pop_left();
            //std::cout<<"lfu is: "<<lfu_count<<'\n';
            //std::cout<<"Full deleting: "<<result<<'\n';
            value_map.erase(result);
            count_map.erase(result);
        }
        //std::cout<<"current size is: "<<value_map.size();
        //std::cout<<'\n';
        //std::cout<<"adding :"<<key<<'\n';
        value_map[key] = value;
        //std::cout<<"size after insertion is: "<<value_map.size();
        //std::cout<<'\n';
        counter(key);
        lfu_count = std::min(lfu_count, count_map[key]);
        /*
        for(auto [key, value]: value_map)
            std::cout<<key<<" : "<<value<<" with count => "<<count_map[key]<<'\n';
        std::cout<<'\n';
        */
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */