class Solution {
public:
    int solve(vector<pair<int,int>> &ones,int i,int j)
    {
        int ans = INT_MAX;
        for(auto x:ones)
            ans = min(ans,abs(i-x.first)+abs(j-x.second));
        return ans;
    }
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> ones;
        int ans = 0,o=0,z=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==1)
                {
                    ones.push_back({i,j});
                    o++;
                }
            }
        }
        if(o==0)
            return -1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==0)
                {
                    ans = max(ans,solve(ones,i,j));
                    z++;
                }
            }
        }
        if(z==0)
            return -1;
        return ans;
    }
};