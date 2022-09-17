class MyCalendarThree {
    unordered_map<int,int> val,lazy;
public:
    MyCalendarThree() {
        
    }
    void push(int v)
    {
        if(lazy[v])
        {
            val[2*v]+=lazy[v];
            val[2*v+1]+=lazy[v];
            lazy[2*v]+=lazy[v];
            lazy[2*v+1]+=lazy[v];
            lazy[v] = 0;
        }
    }
    void update(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return;
        if(tl==l && tr==r)
        {
            val[v]++;
            lazy[v]++;
            return;
        }
        int tm = (tl+tr)/2;
        push(v);
        update(2*v,tl,tm,l,min(r,tm));
        update(2*v+1,tm+1,tr,max(l,tm+1),r);
        val[v] = max(val[2*v],val[2*v+1]);
    }
    int book(int start, int end) {
        update(1,0,1e9,start,end-1);
        return val[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */