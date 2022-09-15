class Solution {
    vector<int> st,marked;
    int n;
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
            marked[v] = 1;
            st[v] = val;
            return;
        }
        push(v);
        int tm = (tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,val);
    }
    int query(int v,int tl,int tr,int i)
    {
        if(tl==tr || marked[v])
            return st[v];
        push(v);
        int tm = (tl+tr)/2;
        if(i<=tm)
            return query(2*v,tl,tm,i);
        return query(2*v+1,tm+1,tr,i);
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> heights,ans;
        unordered_set<int> set;
        vector<int> maxi,points;
        for(auto &x:buildings)
        {
            if(set.count(x[0])==0)
            {
                points.push_back(x[0]);
                points.push_back(x[0]);
                set.insert(x[0]);
            }
            if(set.count(x[1])==0)
            {
                points.push_back(x[1]);
                points.push_back(x[1]);
                set.insert(x[1]);
            }
            heights.push_back({x[2],x[0],x[1]});
        }
        sort(points.begin(),points.end());
        sort(begin(heights),end(heights));
        n = points.size();
        st.assign(4*n,0);
        marked.assign(4*n,0);
        for(auto &x:heights)
        {
            int l = upper_bound(begin(points),end(points),x[1])-begin(points);
            int r = lower_bound(begin(points),end(points),x[2])-begin(points);
            l--;
            update(1,0,n-1,l,r,x[0]);
        }
        for(int i=0;i<n;i++)
        {
            maxi.push_back(query(1,0,n-1,i));
        }
        for(int i=1;i<n;i++)
        {
            // cout<<points[i][0]<<" "<<points[i][1]<<" "<<maxi[i]<<endl;
            if(maxi[i]!=maxi[i-1])
            {
                ans.push_back({points[i],maxi[i]});
            }
        }
        return ans;
    }
};