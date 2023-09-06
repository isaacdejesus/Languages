#include<iostream>
class RandomizedSet {
public:
       std::unordered_map<int, int> hash;
       std::vector<int> vec; 
    RandomizedSet() {
        hash = {};
        vec = {};
    }
    
    bool insert(int val) {
        bool in_hash = hash.count(val) > 0;
       if(!in_hash) 
       {
            hash[val] = vec.size();
            vec.push_back(val);
            return true;
       }
        return false;
    }
    
    bool remove(int val) {
        bool in_hash = hash.count(val > 0);
        if(hash.count(val) > 0)
        {
            int index = hash[val];
            int last_val_in_list = vec[vec.size() - 1];
            vec[index] = last_val_in_list;
            vec.pop_back();
            hash[last_val_in_list] = index;
            hash.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
            return vec[std::rand() % vec.size()];
    }
};
