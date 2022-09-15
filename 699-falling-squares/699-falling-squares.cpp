class Solution {
    vector<int> st,marked;
    void push(int v)
    {
        if(marked[v])
        {
            st[2*v] = st[2*v+1] = st[v];
            marked[2*v] = marked[2*v+1] = 1;
            marked[v] = 0;
        }
    }
    void update(int v,int tl,int tr,int l,int r,int val)
    {
        if(l>r)
            return;
        if(tl==l && tr==r)
        {
            st[v] = val;
            marked[v] = 1;
            return;
        }
        push(v);
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,val);
        st[v] = max(st[2*v],st[2*v+1]);
    }
    
    int query(int v,int tl,int tr,int l,int r)
    {
        if(l>r)
            return 0;
        if(tl==l && tr==r)
            return st[v];
        push(v);
        int tm = (tl+tr)/2;
        return max(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
    void add(int l,int r,int h,vector<int> &heights,int &maxh)
    {
        int t = 0;
        for(int i=l;i<=r;i++)
            t = max(t,heights[i]);
        for(int i=l;i<=r;i++)
            heights[i] = t+h;
        maxh = max(maxh,t+h);
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> heights,maxi,ans;
        for(auto x:positions)
        {
            heights.push_back(x[0]);
            heights.push_back(x[1]+x[0]);
        }
        sort(begin(heights),end(heights));
        heights.erase(unique(begin(heights),end(heights)),end(heights));
        int n = heights.size(),maxh=0;
        for(int i=0;i<n;i++)
            heights.push_back(heights[i]);
        sort(begin(heights),end(heights));
        n = heights.size();
        st.assign(4*n,0);
        marked.assign(4*n,0);
        maxi.assign(n,0);
        for(auto x:positions)
        {
            int l = upper_bound(heights.begin(),end(heights),x[0])-begin(heights);
            int r = lower_bound(heights.begin(),end(heights),x[0]+x[1])-begin(heights);
            l--;
            int t = query(1,0,n-1,l,r);
            update(1,0,n-1,l,r,t+x[1]);
            maxh = max(maxh,t+x[1]);
            ans.push_back(maxh);
        }
        return ans;
    }
};