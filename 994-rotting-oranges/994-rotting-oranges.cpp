class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rotten=0,fresh = 0,n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                {
                    rotten++;
                    q.push({i,j});
                }
            }
        }
        // cout<<fresh<<" "<<rotten<<endl;
        if(fresh==0)
            return 0;
        if(rotten == 0)
            return -1;
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto top = q.front();
                q.pop();
                int r= top.first,c=top.second;
                if(r>0 && grid[r-1][c]==1)                    
                {
                    q.push({r-1,c});
                    grid[r-1][c]=2;
                }
                if(r<n-1 && grid[r+1][c]==1)                    
                {
                    q.push({r+1,c});
                    grid[r+1][c]=2;
                }
                if(c>0 && grid[r][c-1]==1)                    
                {
                    q.push({r,c-1});
                    grid[r][c-1]=2;
                }
                if(c<m-1 && grid[r][c+1]==1)                    
                {
                    q.push({r,c+1});
                    grid[r][c+1]=2;
                }
            }
            if(!q.empty())
                ans++;
            // cout<<ans<<endl;
        }
        fresh = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        // cout<<fresh;
        if(fresh)
            return -1;
        return ans;
    }
    
};