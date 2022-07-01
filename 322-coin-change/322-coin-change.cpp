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
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,coins,amount);
        if(ans>10000)
            return -1;
        return ans;
    }
};