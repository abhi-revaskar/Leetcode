class Solution {
    vector<int> t;
    
    void build(int i,int l,int r)
    {
        if(l==r)
            t[i] = l;
        else
        {
            int m = (l+r)/2;
            build(2*i,l,m);
            build(2*i+1,m+1,r);
            t[i] = max(t[2*i],t[2*i+1]);
        }
    }
    
    void update(int v,int tl,int tr,int i,int val)
    {
        if(i<tl || i>tr)
            return;
        if(tl==tr)
        {
            t[v] = val;
            return;
        }
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,i,val);
        update(2*v+1,tm+1,tr,i,val);
        t[v] = max(t[2*v],t[2*v+1]);
    }
    
    int query(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return 0;
        if(tl==l && tr==r)
            return t[v];
        int tm = (tl+tr)/2;
        return max(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(),maxn = (*max_element(nums.begin(),nums.end())+1);
        t.assign(4*maxn,0);
        for(auto x:nums)
        {
            int lis = query(1,0,maxn-1,max(0,x-k),x-1);
            update(1,0,maxn-1,x,lis+1);
        }
        return *max_element(t.begin(),t.end());
    }
};