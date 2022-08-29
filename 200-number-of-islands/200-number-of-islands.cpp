class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid)
    {
        if(min(i,j)<0 || i==grid.size() || j==grid[0].size() || grid[i][j]!='1')
            return;
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0,n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};