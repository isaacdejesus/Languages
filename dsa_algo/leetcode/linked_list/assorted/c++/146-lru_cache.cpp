class Node 
{
    public: 
        int k;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int value)
        {
            k = key;
            val = value;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
private:
    int cap;
    std::unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

public:
    LRUCache(int capacity) {
       cap = capacity;
       left = new Node(0, 0); //create nodes that point to each other when list ini
       right = new Node(0, 0);
       left->next = right;
       right->prev = left;
    }
    
    int get(int key) {
       if(cache.count(key) > 0)
       {
           remove(cache[key]); //if item in list, delete it and add it to the end 
           insert(cache[key]);  //adding to end makes it most recently used
           return cache[key]->val;  //return val
       }
       return -1; //item not in hash, return -1
    }
    
    void put(int key, int value) 
    {
       if(cache.count(key) > 0) 
       {
           remove(cache[key]); //already in hash, delete to ++ recency/add to end later
           delete cache[key]; //delete pointer/free up mem
       }
       cache[key] = new Node(key, value);
       insert(cache[key]);
       if(cache.size() > cap)
       {
           Node* lru = left->next;
           remove(lru);  //delete from linked list
           cache.erase(lru->k); //delete from hash
           delete lru;  //delete pointer/free up mem
       }
    }
private:
    void remove(Node* node) // deletion is easier bc we have 2 dummy nodes at both ends
    { //whenever list is empty they will just point at each other. left -> right and right-> left
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node) //add to the end
    {
        Node* prev = right->prev;
        Node* next = right;
        prev->next = node;
        next->prev = node;
        node->prev = prev;
        node->next = next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */