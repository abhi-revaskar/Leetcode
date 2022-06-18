class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> prev(m),curr(m);
        prev[m-1] = grid[n-1][m-1];
        for(int j=m-2;j>=0;j--)
        {
            prev[j]=prev[j+1]+grid[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            curr[m-1] = grid[i][m-1] + prev[m-1];
            for(int j=m-2;j>=0;j--)
            {
                curr[j] = min(curr[j+1],prev[j]) + grid[i][j];
            }
            prev = curr;
        }
        return prev[0];
    }
};