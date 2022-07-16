class Solution {
public:
    vector<int> dfs;
    void solve(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &trav)
    {
        vis[i] = 1;
        for(auto x:adj[i])
        {
            if(!vis[x])
                solve(x,adj,vis,trav);
            else if(!trav[x])
            {
                dfs.push_back(-1);
                return;
            }
        }
        trav[i]=1;
        dfs.push_back(i);
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0),trav(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                solve(i,adj,vis,trav);
        }
        reverse(dfs.begin(),dfs.end());
        for(auto x:dfs)
            if(x==-1)
                return {};
        return dfs;
    }
};