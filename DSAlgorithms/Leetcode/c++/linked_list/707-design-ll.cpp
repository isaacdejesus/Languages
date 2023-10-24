class Node 
{
public:
    int val;
    Node* next;
    Node* prev;

    Node()
    {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
       head = nullptr; 
       tail = nullptr;
       size = 0;
    }
    
    int get(int index) {
       Node* current = head; 
       if(index < 0 && index > size - 1)
            return -1;
        if(index == 0 && size > 0)
            return head->val;
       while(current != nullptr && index >= 0)
       {
            if(index == 0)    
               return current->val;
            current = current->next;
            index--;
       }
       return -1;
    }
    
    void addAtHead(int val) {
       Node* new_node = new Node();
       new_node->val = val;
       //list if empty
       if(head == nullptr && tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }
    
    void addAtTail(int val) {
       Node* new_node = new Node();
       new_node->val = val;
       //list is empty
       if( head == nullptr && tail == nullptr)
       {
           head = new_node;
           tail = new_node;
       }
       //There is at least one node
       else
       {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
       }
       size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index ==  size )
        {
            addAtTail(val);
            return;
        }
        
        if(index > size)
            return;
        Node* new_node = new Node();
        new_node->val = val;
        Node* current = head;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        else
        {
        while(current != nullptr)
        {
            if(index == 0)
                break;
            index--;
            current = current->next;
        }
            current->prev->next = new_node;
            new_node->prev = current->prev; 
            current->prev = new_node;
            new_node->next = current;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        //list is empty
        if(head == nullptr && tail == nullptr)
            return;
        if(index < 0 || index >= size)
            return;
        //delete only node
        if(index == 0 && size == 1)
        {
            Node* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
            size--;
        }
        //deleting first element
        else if(index == 0)
        {
            Node* temp = head;
            head->next->prev = nullptr;
            head = head -> next;
            delete temp;
            size--;
        }
        //delete at tail
        else if(index == size - 1)
        {
            Node* temp = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
            size--;
        }
        //delete from mid
        else if(size > 2)
        {
            Node* temp = head;
            while(temp != nullptr)
            {
                if(index == 0)
                    break;
                index--;
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */