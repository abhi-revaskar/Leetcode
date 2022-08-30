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
        // memset(dp,-1,sizeof(dp));
        // int ans =  solve(0,amt,coins);
        // if(ans>10000)
        //     return -1;
        // return ans;
        vector<int> dp(amt+1,0),prev(amt+1,0);
        for(int i=1;i<=amt;i++)
            prev[i]=10001;
        for(int i=1;i<=coins.size();i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(j<coins[i-1])
                    dp[j] = prev[j];
                else
                    dp[j] = min(dp[j-coins[i-1]]+1,prev[j]);
            }
            prev = dp;
        }
        return prev.back()==10001?-1:prev.back();
    }
};