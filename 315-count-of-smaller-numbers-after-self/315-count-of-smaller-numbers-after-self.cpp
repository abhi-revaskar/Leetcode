class Solution {
    vector<int> st;
    int n;
    
    void update(int v,int tl,int tr,int i)
    {
        if(tl==tr)
        {
            st[v]++;
            return;
        }
        int tm = (tl+tr)/2;
        if(i<=tm)
            update(2*v,tl,tm,i);
        else
            update(2*v+1,tm+1,tr,i);
        st[v] = st[2*v] + st[2*v+1];
    }
    
    int sum(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return 0;
        if(tl==l && tr==r)
        {
            return st[v];
        }
        int tm = (tr+tl)/2;
        return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sorted(nums),ans(nums.size());
        n = nums.size();
        st.resize(4*n,0);
        sort(sorted.begin(),end(sorted));
        for(int i=n-1;i>=0;i--)
        {
            int idx= lower_bound(sorted.begin(),sorted.end(),nums[i])-begin(sorted);
            if(idx==0)
                ans[i] = 0;
            else
                ans[i] = sum(1,0,n-1,0,idx-1);
            update(1,0,n-1,idx);
        }
        return ans;
    }
};