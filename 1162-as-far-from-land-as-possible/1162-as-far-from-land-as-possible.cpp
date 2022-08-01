class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(),o=0,z=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    o++;
                    q.push({i,j});
                }
            }
        }
        if(o==0)
            return -1;
        int ans = -1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto x = q.front();
                q.pop();
                int i = x.first,j=x.second;
                if(i>0 && grid[i-1][j]==0)
                {
                    q.push({i-1,j});
                    grid[i-1][j]=1;
                    z++;
                }
                if(i<n-1 && grid[i+1][j]==0)
                {
                    q.push({i+1,j});
                    grid[i+1][j]=1;
                    z++;
                }
                if(j>0 && grid[i][j-1]==0)
                {
                    q.push({i,j-1});
                    grid[i][j-1]=1;
                    z++;
                }
                if(j<n-1 && grid[i][j+1]==0)
                {
                    q.push({i,j+1});
                    grid[i][j+1]=1;
                    z++;
                }
            }
            ans++;
        }
        if(z==0)
            return -1;
        return ans;
    }
};