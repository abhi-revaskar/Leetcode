class Solution {
public:
    int dp[13][10001];
    int solve(int i,vector<int> &coins,int amt)
    {
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        if(amt == 0)
            return dp[i][amt]=0;
        if(i==coins.size() || amt<0)
            return 10001;
        int ans = 10001;
        ans = min(ans,solve(i+1,coins,amt));
        if(coins[i]<=amt)
            ans = min(ans,1+solve(i,coins,amt-coins[i]));
        return dp[i][amt]=ans;
    }
    int coinChange(vector<int>& coins, int amt) {
        // memset(dp,-1,sizeof(dp));
        // int ans = solve(0,coins,amount);
        // if(ans>10000)
        //     return -1;
        vector<vector<int>> dp(coins.size()+1,vector<int>(amt+1,10001));
        dp[0][0] = 0;
        for(int i=1;i<=coins.size();i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=amt;j++)
            {
                dp[i][j] = min(dp[i-1][j],coins[i-1]>j?INT_MAX:1+dp[i][j-coins[i-1]]);
            }
        }
        return dp[coins.size()][amt]>10000?-1:dp[coins.size()][amt];
    }
};