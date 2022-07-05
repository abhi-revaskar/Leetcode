class Solution {
public:
    int dp[1001][101];
    int solve(int i,int k,vector<int> &prices)
    {
        if(dp[i][k]!=-1)
            return dp[i][k];
        if(k==0 || i==prices.size())
            return dp[i][k] = 0;
        int ans = 0,mini=prices[i],curr=0;
        for(int idx=i+1;idx<prices.size();idx++)
        {
            if(prices[idx]<mini)
            {
                mini = prices[idx];
            }
            else if(prices[idx]>mini)
            {
                curr=max(curr,prices[idx]-mini);
                ans = max(ans,curr+solve(idx,k-1,prices));
            }
        }
        return dp[i][k] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0 || k==0)
            return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,k,prices);
    }
};