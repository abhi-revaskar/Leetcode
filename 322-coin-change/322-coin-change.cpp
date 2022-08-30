class Solution {
public:
    int dp[13][10001];
    int solve(int i,int amt,vector<int> &coins)
    {
        if(amt==0)
            return 0;
        if(i==coins.size() || coins[i]>amt)
            return 10001;
        if(dp[i][amt]!=-1)
            return dp[i][amt];
        return dp[i][amt] = min(solve(i+1,amt,coins),1+solve(i,amt-coins[i],coins));
    }
    int coinChange(vector<int>& coins, int amt) {
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        int ans =  solve(0,amt,coins);
        if(ans>10000)
            return -1;
        return ans;
    }
};