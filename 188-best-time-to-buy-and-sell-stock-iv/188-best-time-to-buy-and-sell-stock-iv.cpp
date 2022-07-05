class Solution {
public:
    int dp[1001][201];
    int solve(int i,int trans,vector<int> &prices)
    {
        if(dp[i][trans]!=-1)
            return dp[i][trans];
        if(i==prices.size() || trans == 0)
            return dp[i][trans]= 0;
        if(trans&1)
            return dp[i][trans] =  max(prices[i]+solve(i+1,trans-1,prices),solve(i+1,trans,prices));
        return dp[i][trans] = max(-prices[i]+solve(i+1,trans-1,prices),solve(i+1,trans,prices));
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,2*k,prices);
    }
};