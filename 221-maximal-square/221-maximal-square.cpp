class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> m(matrix.size(),vector<int> (matrix[0].size()));
        int ans = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                m[i][j] = matrix[i][j]-'0';
                ans = max(ans,m[i][j]);
            }
        }
        vector<int> prev(m[0]),dp(matrix[0].size(),0);
        for(int i = 1;i<m.size();i++)
        {
            int c = m[i][0];
            dp=m[i];
            for(int j = 1;j<m[0].size();j++)
            {
                if(m[i][j])
                {
                    int side = min(c,m[i-1][j]);
                    side = min(prev[j-1],side);
                    side++;
                    ans = max(ans,side*side);                        
                    dp[j]=side;
                    c++;
                    m[i][j]+=m[i-1][j];
                }
                else
                    c=0;
                
                // cout<<i<<":"<<dp[j]<<" ";
            }
            // cout<<endl;
            prev=dp;
        }
        return ans;
    }
};