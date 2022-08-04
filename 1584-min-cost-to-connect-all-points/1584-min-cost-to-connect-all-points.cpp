class DSU{
    public:
    vector<int> par,rank;
    DSU(int n)
    {
        rank.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    int find(int node)
    {
        if(par[node]==node)
            return node;
        return par[node] = find(par[node]);
    }
    void add(int a,int b)
    {
        int par_a = find(a);
        int par_b = find(b);
        if(rank[par_a]==rank[par_b])
            rank[par_a]++;
        if(rank[par_a]>rank[par_b])
            par[par_b] = par_a;
        else
            par[par_a] = par_b;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({dist,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        DSU *obj = new DSU(points.size());
        int ans = 0;
        for(auto x:adj)
        {
            int u = x.second.first,v=x.second.second;
            if(obj->find(u)!=obj->find(v))
            {
                obj->add(u,v);
                ans+=x.first;
            }
        }
        return ans;
    }
};