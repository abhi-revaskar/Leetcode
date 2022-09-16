class RangeModule {
    vector<pair<int,int>> s,t;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        int i=0;
        while(i<s.size() && s[i].second<left)
            t.push_back(s[i++]);
        while(i<s.size() && s[i].first<=right)
        {
            left = min(left,s[i].first);
            right = max(right,s[i++].second);
        }
        t.push_back({left,right});
        while(i<s.size())
            t.push_back(s[i++]);           
        s = t;
        t.clear();
    }
    
    bool queryRange(int left, int right) {
        auto l = upper_bound(s.begin(),s.end(),make_pair(left,INT_MAX));
        if(l==s.begin())
            return false;
        l--;
        if((l->first)<=left && (l->second)>=right)
            return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        int i=0;
        while(i<s.size() && s[i].second<left)
            t.push_back(s[i++]);
        while(i<s.size() && s[i].first<=right)
        {
            if(s[i].first<left)
                t.push_back({s[i].first,left});
            if(s[i].second>right)
                t.push_back({right,s[i].second});
            i++;
        }
        while(i<s.size())
            t.push_back(s[i++]);           
        s = t;
        t.clear();
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */