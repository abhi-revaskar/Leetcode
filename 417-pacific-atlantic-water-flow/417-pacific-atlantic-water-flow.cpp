class Solution {
public:
    void dfs(int i,int j,int k,vector<vector<int>> &vis,vector<vector<int>> &h)
    {
        if(min(i,j)<0 || i==h.size() || j==h[0].size() || vis[i][j] || h[i][j]<k) return;
        vis[i][j] = 1;
        dfs(i-1,j,h[i][j],vis,h);
        dfs(i+1,j,h[i][j],vis,h);
        dfs(i,j-1,h[i][j],vis,h);
        dfs(i,j+1,h[i][j],vis,h);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(),m=h[0].size();
        vector<vector<int>> ans,pac(n,vector<int> (m,0)),atl(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            dfs(i,0,h[i][0],pac,h);
            dfs(i,m-1,h[i][m-1],atl,h);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,h[0][i],pac,h);
            dfs(n-1,i,h[n-1][i],atl,h);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
