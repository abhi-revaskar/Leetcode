class MyCalendarThree {
    unordered_map<int,int> st,lazy;
    void push(int v)
    {
        if(lazy[v])
        {
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
            st[2*v]+=lazy[v];
            st[2*v+1]+=lazy[v];
            lazy[v] = 0;     
        }
    }
    void update(int v,int tl,int tr,int l,int r)
    {
        if(l>r) return ;
        if(tl==l && tr==r)
        {
            lazy[v]++;
            st[v]++;
            return;
        }
        push(v);
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm));
        update(2*v+1,tm+1,tr,max(tm+1,l),r);
        st[v] = max(st[2*v],st[2*v+1]);
    }
    int query(int v,int l,int r)
    {
        push(v);
        return st[v];
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        update(1,0,1e9,start,end-1);
        int ans = query(1,0,1e9);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */