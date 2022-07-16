class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj)
    {
        vis[i]=1;
        for(int j=0;j<vis.size();j++)
        {
            if(adj[i][j]==1 && !vis[j])
                dfs(j,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        int ans = 0;
        for(int i=0;i<vis.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,isConnected);
                ans++;
            }
        }
        return ans;
    }
};