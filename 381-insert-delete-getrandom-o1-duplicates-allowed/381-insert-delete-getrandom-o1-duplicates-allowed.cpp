class RandomizedCollection {
public:
    unordered_map<int,unordered_set<int>> mp;
    vector<int> s;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans;
        if(mp.find(val)!=mp.end())
            ans = false;
        else 
            ans = true;
        s.push_back(val);
        mp[val].insert(s.size()-1);
        return ans;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int idx = *mp[val].begin();
        int last = s.size()-1;
        swap(s[idx],s[last]);
        mp[val].erase(idx);
        mp[s[idx]].insert(idx);
        mp[s[idx]].erase(last);
        s.pop_back();
        if(mp[val].empty())
            mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return s[rand()%s.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */