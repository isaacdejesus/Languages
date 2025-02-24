class Node
{
    public:
        int val;
        Node* next;
        Node(int val_ )
        {
            val = val_;
            next = nullptr;
        }
};
class MyCircularQueue {
public:
    Node* head;
    Node* tail;
    int capacity;
    int size;
    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        capacity = k;
        size = 0;
    }
    
    bool enQueue(int value) {
       if(isFull()) 
            return false;
        Node* new_node = new Node(value);
        //emty, adding first value
        if(size == 0)
        {
            head = new_node;
            tail = new_node;
        }
        else //add to end of list
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())    
            return false;
        head = head->next;
        size--;
        return true;
    }
    
    int Front() {
       if(isEmpty()) 
            return -1;
        else 
            return head->val;
    }
    
    int Rear() {
       if(isEmpty()) 
            return -1;
        else
            return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;     
    }
    
    bool isFull() {
        return capacity == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */