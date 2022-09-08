class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(min(i,j)<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==0)
            return;
        grid[i][j] = 0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    bool isdisconnected(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size(),f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && f)
                    return true;
                if(grid[i][j])
                {
                    dfs(i,j,grid);
                    f=1;
                }
            }
        }
        if(!f)
            return true;
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        if(isdisconnected(grid))
            return 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    grid[i][j] = 0;
                    if(isdisconnected(grid))
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};