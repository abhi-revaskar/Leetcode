class Solution {
public:
    int check(int i,int j,vector<int> &compo,vector<vector<int>> &grid)
    {
        unordered_set<int> s;
        if(i>0)
            s.insert(grid[i-1][j]);
        if(j>0)
            s.insert(grid[i][j-1]);
        if(i<grid.size()-1)
            s.insert(grid[i+1][j]);
        if(j<grid.size()-1)
            s.insert(grid[i][j+1]);
        int ans = 1;
        for(auto x:s)
            ans+=compo[x];
        return ans;
    }
    int solve(int i,int j,int no,vector<vector<int>> &grid)
    {
        if(min(i,j)<0 || max(i,j)==grid.size() || grid[i][j]!=1)
            return 0;
        int ans = 1;
        grid[i][j]=no;
        ans+=solve(i+1,j,no,grid);
        ans+=solve(i-1,j,no,grid);
        ans+=solve(i,j+1,no,grid);
        ans+=solve(i,j-1,no,grid);
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(),no=2,ans = -1;
        vector<int> compo(n*n+2,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    compo[no]=(solve(i,j,no,grid));
                    no++;
                }
            }
        }
        for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    ans = max(ans,check(i,j,compo,grid));
            }
       }
        return (ans==-1)?(n*n):ans;
    }
};