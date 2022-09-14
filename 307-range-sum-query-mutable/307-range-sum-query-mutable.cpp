class NumArray {
    vector<int> st;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.assign(15*1e4,0);
        build(1,0,n-1,nums);
    }
    void build(int v,int tl,int tr,vector<int> &nums)
    {
        if(tl==tr)
        {
            st[v] = nums[tl];
            return;
        }
        int mid = (tl+tr)/2;
        build(2*v+1,tl,mid,nums);
        build(2*v+2,mid+1,tr,nums);
        st[v] = st[2*v+1]+st[2*v+2];
    }
    
    void update(int v,int tl,int tr,int i,int val)
    {
        if(tl==tr)
        {
            st[v] = val;
            return;
        }
        int mid = (tl+tr)/2;
        if(i<=mid)
        update(2*v+1,tl,mid,i,val);
        else
        update(2*v+2,mid+1,tr,i,val);
        st[v] = st[2*v+1]+st[2*v+2];
    }
    void update(int index, int val) {
        update(1,0,n-1,index,val);
    }
    int sum(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return 0;
        if(tl==l && tr==r)
            return st[v];
        int tm = (tl+tr)/2;
        return sum(2*v+1,tl,tm,l,min(r,tm))+sum(2*v+2,tm+1,tr,max(l,tm+1),r);
    }
    int sumRange(int left, int right) {
        return sum(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */