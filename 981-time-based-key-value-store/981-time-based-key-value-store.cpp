class TimeMap {
public:
    unordered_map<string,set<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({-timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto ans = mp[key].lower_bound({-timestamp,""});
        return ans->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */