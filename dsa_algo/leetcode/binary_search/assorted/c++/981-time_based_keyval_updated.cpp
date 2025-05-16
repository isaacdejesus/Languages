//ugh, memory limit excedeed still
class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::string>> values_hash;
    std::unordered_map<std::string, std::vector<int>> time_hash;
    TimeMap() {
       values_hash = {};
       time_hash = {};
    }
    
    void set(string key, string value, int timestamp) {
        std::vector<std::string> temp_vals;
        std::vector<int> temp_times;
       if(values_hash.count(key) > 0) 
       {
           temp_vals = values_hash[key];
           temp_times = time_hash[key];
           temp_vals.push_back(value);
           temp_times.push_back(timestamp);
           values_hash[key] = temp_vals;
           time_hash[key] = temp_times;
       }
       else
       {
           temp_vals.push_back(value);
           temp_times.push_back(timestamp);
           values_hash[key] = temp_vals;
           time_hash[key] = temp_times;
       }
    }
    
    string get(string key, int timestamp) {
        std::string result = "";
        //std::vector<int> times = time_hash[key];
        //std::vector<std::string> vals = values_hash[key];

        int left = 0;
        //int right = times.size() - 1;
        int right = values_hash[key].size() -1;
        while(left <= right)
        {
            int mid = left + (right - left) /2;
            //if(times[mid] <= timestamp)
            if(time_hash[key][mid] <= timestamp)
            {
                //result = vals[mid];
                result = values_hash[key][mid];
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */