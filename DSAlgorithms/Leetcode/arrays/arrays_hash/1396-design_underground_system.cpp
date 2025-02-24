class UndergroundSystem {
public:
    std::unordered_map<int, std::string> check_in_hash;
    std::unordered_map<std::string, std::vector<double>> total_hash;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        std::string concat = stationName + '.' + std::to_string(t);
        check_in_hash[id] = concat;
    }
    
    void checkOut(int id, string stationName, int t) {
       if(check_in_hash.count(id) > 0) 
       {
            std::string check_in_data = check_in_hash[id];
        std::string start = check_in_data.substr(0, check_in_data.find('.') );
        int time = stoi(check_in_data.substr(check_in_data.find('.') + 1));
        std::string route = start + '.' + stationName;
        if(!(total_hash.count(route) > 0))
        {
            std::vector<double> temp = {0, 0};
            total_hash[route] = temp; 
        }
        std::vector<double> temp = total_hash[route];
        temp[0] += t - time;
        temp[1] += 1;
        total_hash[route] = temp;
        std::cout<<"adding route: "<<route<<'\n';
       }
    }
    
    double getAverageTime(string startStation, string endStation) {
       std::string key = startStation + '.' + endStation;
       std::cout<<"key is: "<<key<<'\n';
       if(total_hash.count(key) > 0) 
        {
            std::vector<double> data = total_hash[key];
            std::cout<<data[0]<<" "<<data[1]<<'\n';
            return data[0] / data[1];
        }
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */