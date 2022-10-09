class Solution {
    const int mm = 1e9+7;
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> vis;
    void solve(int i,int j,int n,int m,vector<vector<int>>& grid,int k)
    {
        if(min(i,j)<0 || i==n || j==m || vis[i][j])
            return;
        vis[i][j] = 1;
        if(i==n-1 && j==m-1)
        {
            dp[i][j][grid[i][j]%k]=1;
            return;
        }
        solve(i,j+1,n,m,grid,k);
        solve(i+1,j,n,m,grid,k);
        int x = grid[i][j];
        if(i<n-1)
        {
            // cout<<i<<" "<<j<<"| ";
            for(int mod = 0;mod<k;mod++)
            {
                dp[i][j][mod] = (dp[i][j][mod] + dp[i+1][j][(k-(x%k)+mod)%k])%mm;
                // cout<<mod<<" "<<dp[i][j][mod]<<endl;
            }
        }
        if(j<m-1)
        {
            for(int mod = 0;mod<k;mod++)
                dp[i][j][mod] = (dp[i][j][mod] + dp[i][j+1][(k-(x%k)+mod)%k])%mm;
        }
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();
        dp.resize(n,vector<vector<int>> (m,vector<int> (k,0)));
        vis.resize(n,vector<int> (m,0));
        solve(0,0,n,m,grid,k);
        // for(auto x:dp)
        // {
        //     for(auto y:x)
        //     {
        //         for(auto mod:y)
        //             cout<<mod<<" ";
        //         cout<<"| ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0][0];
    }
};