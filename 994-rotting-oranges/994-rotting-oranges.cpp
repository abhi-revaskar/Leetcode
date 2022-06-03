class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=-1,flag=0;
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    
                    flag=1;
                }
                if(grid[i][j]==1)
                    flag=1;
            }
        }
        if(!flag)
            return 0;
        if(q.empty())
        return -1;
        while (!q.empty())
        {
            int currsize=q.size();
            while (currsize--)
            {
                auto t=q.front();
                int u=t.first-1,d=t.first+1,l=t.second-1,r=t.second+1;
                if(u>=0 && grid[u][t.second]==1)
                {
                    q.push({u,t.second});
                    grid[u][t.second]=2;
                    
                }
                if(d<n && grid[d][t.second]==1)
                {
                    q.push({d,t.second});
                    grid[d][t.second]=2;
                    
                }
                if(l>=0 && grid[t.first][l]==1)
                {
                    q.push({t.first,l});
                    grid[t.first][l]=2;
                    
                }
                if(r<m && grid[t.first][r]==1)
                {
                    q.push({t.first,r});
                    grid[t.first][r]=2;
                
                }
                q.pop();
            }
            ans++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }

};