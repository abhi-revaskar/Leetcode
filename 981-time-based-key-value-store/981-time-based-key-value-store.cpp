class TimeMap {
public:
    unordered_map<string,set<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto ans = mp[key].upper_bound({timestamp,""});
        if(mp[key].empty())
            return "";
        if(ans->first==timestamp)
            return ans->second;
        if(ans ==mp[key].begin())
            return "";
        ans--;
        return ans->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */