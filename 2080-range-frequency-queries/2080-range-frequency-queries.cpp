class RangeFreqQuery {
    unordered_map<int,unordered_map<int,int>> mp;
    int n;
public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        build(1,0,arr.size()-1,arr);
    }
    void build(int v,int l,int r,vector<int> &arr)
    {
        if(l==r)
        {
            mp[v][arr[l]]++;
            return;
        }
        int m = (l+r)/2;
        build(2*v,l,min(r,m),arr);
        build(2*v+1,max(l,m+1),r,arr);
        for(auto x:mp[2*v])
        {
            if(mp[v].count(x.first))
                mp[v][x.first]+=x.second;
            else
                mp[v].insert({x.first,x.second});
        }
        for(auto x:mp[2*v+1])
        {
            if(mp[v].count(x.first))
                mp[v][x.first]+=x.second;
            else
                mp[v].insert({x.first,x.second});
        }
    }
    int query(int v,int tl,int tr,int l,int r,int val)
    {
        if(l>r)
            return 0;
        if(tl==l && tr==r)
            return mp[v][val];
        int tm = (tl+tr)/2; 
        return query(2*v,tl,tm,l,min(r,tm),val)+query(2*v+1,tm+1,tr,max(l,tm+1),r,val);
    }
    int query(int left, int right, int value) {
        return query(1,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */