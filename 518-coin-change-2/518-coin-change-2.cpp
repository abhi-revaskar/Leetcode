class Solution {
public:
    int dp[301][5001];
    int solve(int i,int amt,vector<int> &coins)
    {
        if(amt==0)
            return 1;
        if(i==coins.size() || amt<coins[i])
            return 0;
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        return dp[i][amt] = solve(i,amt-coins[i],coins)+solve(i+1,amt,coins);
    }
    int change(int amt, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        // memset(dp,-1,sizeof(dp));
        // return solve(0,amt,coins);
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amt+1,0));
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = 1;
            for(int j=1;j<=amt;j++)
            {
                if(j<coins[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
        return dp.back().back();
    }
};