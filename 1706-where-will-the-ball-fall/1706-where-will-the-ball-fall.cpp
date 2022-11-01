class Solution {
public:
    int solve(int r,int c,int n,int m, vector<vector<int>>& grid)
    {
        if(r==n)
            return c;
        if(grid[r][c]==1 && (c==m-1 || grid[r][c+1]==-1))
            return -1;
        if(grid[r][c]==-1 && (c==0 || grid[r][c-1]==1))
            return -1;
        if(grid[r][c]==1)
            return solve(r+1,c+1,n,m,grid);
        else
            return solve(r+1,c-1,n,m,grid);
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size());
        int n = grid.size(),m = grid[0].size();
        for(int i=0;i<m;i++)
        {
            ans[i] = solve(0,i,n,m,grid);
        }
        return ans;
    }
};