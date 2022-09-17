class CountIntervals {
    unordered_map<int,int> st,marked;
public:
    CountIntervals() {
        
    }
    void update(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return;
        if(marked[v])
            return;
        if(tl==l && tr==r)
        {
            marked[v] = 1;
            st[v] = r-l+1;
            return;
        }
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm));
        update(2*v+1,tm+1,tr,max(l,tm+1),r);
        st[v] = st[2*v] + st[2*v+1];
    }
    void add(int left, int right) {
        update(1,0,1e9,left,right);
    }
    
    int count() {
     return st[1];
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */