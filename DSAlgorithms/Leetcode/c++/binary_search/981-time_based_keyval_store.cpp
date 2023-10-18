/*
    Design time-based key-value structure, multiple vals at diff times

    Hash map, since timestamps are naturally in order, binary search

    Time: O(log n)
    Space: O(n)
*/

class TimeMap {
public:
    std::unordered_map<string, std::vector<pair<int, std::string>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) {
            return "";
        }
        
        int low = 0;
        int high = hash[key].size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hash[key][mid].first < timestamp) {
                low = mid + 1;
            } else if (hash[key][mid].first > timestamp) {
                high = mid - 1;
            } else {
                return hash[key][mid].second;
            }
        }
        
        if (high >= 0) {
            return hash[key][high].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
