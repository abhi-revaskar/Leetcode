class Solution {
public:
    void print(vector<vector<int>> &grid)
    {
        for(int row = 0;row<grid.size();row++)
        {
            for(int col = 0;col<grid.size();col++)
            {
                cout<<grid[row][col]<<" ";
            }
            cout<<endl;
        }
        
    }
    int dist(int i,int j,vector<vector<int>> &grid)
    {
        int ans = INT_MAX;
        for(int row = 0;row<grid.size();row++)
        {
            for(int col = 0;col<grid.size();col++)
            {
                if(grid[row][col]==-1)
                    ans = min(ans,abs(i-row)+abs(j-col)-1);
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid.size() || grid[i][j]!=1)
            return;
        grid[i][j]=-1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int f = 1,ans = INT_MAX;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(f && grid[i][j])
                {
                    dfs(i,j,grid);
                    // print(grid);
                    f=0;
                }
                else if(grid[i][j]==1)
                {
                    ans = min(ans,dist(i,j,grid));
                }
                    
            }
        }
        return ans;
        
    }
};