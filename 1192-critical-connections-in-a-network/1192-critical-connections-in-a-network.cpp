class Solution {
public:
    vector<vector<int>> ans;
    int solve(int node,int par,int depth,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=depth;
        int lowestdepth = depth;
        for(auto x:adj[node])
        {
            if(x!=par && vis[x]==-1)
            {
                int childdepth = solve(x,node,depth+1,adj,vis);
                if(childdepth==depth+1)
                    ans.push_back({node,x});
                else 
                    lowestdepth = min(lowestdepth,childdepth);
                    
            }   
            else if(x!=par)
                lowestdepth = min(lowestdepth,vis[x]);
        }
        return lowestdepth;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        solve(0,-1,0,adj,vis);
        return ans;
    }
};