class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid)
    { 
        grid[i][j]=-1;
        int ans=0;
        if(i>0 && grid[i-1][j]==1)
            ans+=solve(i-1,j,grid);
        if(i<grid.size()-1 && grid[i+1][j]==1)
            ans+=solve(i+1,j,grid);
        if(j>0 && grid[i][j-1]==1)
            ans+=solve(i,j-1,grid);
        if(j<grid[0].size()-1 && grid[i][j+1]==1)
            ans+=solve(i,j+1,grid);
        return ans+1;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans =max(ans,solve(i,j,grid));
            }
        }
        return ans;
    }
};