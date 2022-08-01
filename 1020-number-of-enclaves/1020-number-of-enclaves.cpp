class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid)
    {
        int n=grid.size(),m=grid[0].size();
        if(min(i,j)<0 || i==n || j==m || grid[i][j]==0) //very imp to check out of boundary
            return 0;
        grid[i][j]=0; // very imp to mark as visited
        int ans = 1;
        ans+=dfs(i-1,j,grid);
        ans+=dfs(i+1,j,grid);
        ans+=dfs(i,j-1,grid);
        ans+=dfs(i,j+1,grid);
        return ans;
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1)
                        dfs(i,j,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans+=dfs(i,j,grid);
            }
        }
        return ans;
        
    }
};