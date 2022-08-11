class Solution {
public:
    void dfs2(int node,int par,vector<vector<int>> &adj,vector<int> &count,vector<int> &res)
    {
        for(auto x:adj[node])
        {
            if(x!=par)
            {
                res[x]=res[node]-count[x]+adj.size()-count[x];
            }
        }
        for(auto x:adj[node])
        {
            if(x!=par)
                dfs2(x,node,adj,count,res);
        }
    }
    void dfs(int node,int par,vector<vector<int>> &adj,vector<int> &count,vector<int> &res)
    {
        for(auto x:adj[node])
        {
            if(x!=par)
                dfs(x,node,adj,count,res);
        }
        for(auto x:adj[node])
        {
            if(x!=par)
            {
                count[node]+=count[x];
                res[node]+=res[x]+count[x];
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> count(n,1),res(n,0);
        dfs(0,-1,adj,count,res);
        dfs2(0,-1,adj,count,res);
        return res;
    }
};