class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        vector<int> dp;
        int ans = 0;
        for(auto x:m[0])
            dp.push_back(x-'0');
        for(auto x:dp)
            ans = max(ans,x);
        int prev = dp[0];
        for(int i =1;i<m.size();i++)
        {
            ans = max(ans,m[i][0]-'0');
            prev = dp[0];
            dp[0] = m[i][0]-'0';
            for(int j = 1;j<m[0].size();j++)
            {
                if(m[i][j]=='1')
                {
                    int t = dp[j];
                    // cout<<dp[j]<<" "<<dp[j-1]<<" "<<prev<<endl;
                    dp[j] = min(dp[j],min(dp[j-1],prev))+1;
                    ans = max(ans,dp[j]*dp[j]);
                    prev = t;
                }
                else
                    dp[j]=0;
                cout<<dp[j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};