class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visit,int i,int j)
    {
        visit[i][j]=1;
        if(i>0 && grid[i-1][j]=='1' && !visit[i-1][j])
            dfs(grid,visit,i-1,j);
        if(i<grid.size()-1 && grid[i+1][j]=='1' && !visit[i+1][j])
            dfs(grid,visit,i+1,j);
        if(j>0 && grid[i][j-1] == '1' && !visit[i][j-1])
            dfs(grid,visit,i,j-1);
        if(j<grid[0].size()-1 && grid[i][j+1] == '1' && !visit[i][j+1])
            dfs(grid,visit,i,j+1);            
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> visit(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visit[i][j] && grid[i][j]=='1')
                {
                    dfs(grid,visit,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};