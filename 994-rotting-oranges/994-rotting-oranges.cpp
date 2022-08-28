class Solution {
public:
    bool check(int i,int j,vector<vector<int>> &grid)
    {
        if(min(i,j)<0 || i==grid.size() || j==grid[0].size() || grid[i][j]!=1)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, n = grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        if(fresh==0)
            return 0;
        if(q.empty())
            return -1;
        int ans = -1;
        while(!q.empty())
        {
            ans++;
            int s = q.size();
            while(s--)
            {
                auto x = q.front();q.pop();
                if(check(x.first-1,x.second,grid))
                {
                    q.push({x.first-1,x.second});
                    grid[x.first-1][x.second]=2;
                }
                if(check(x.first+1,x.second,grid))
                {
                    q.push({x.first+1,x.second});
                    grid[x.first+1][x.second]=2;
                }
                if(check(x.first,x.second-1,grid))
                {
                    q.push({x.first,x.second-1});
                    grid[x.first][x.second-1]=2;
                }
                if(check(x.first,x.second+1,grid))
                {
                    q.push({x.first,x.second+1});
                    grid[x.first][x.second+1]=2;
                }
            }
        }
        for(auto x:grid)
            for(auto y:x)
                if(y==1)
                    return -1;
        return ans;
    }
};