class Solution {
public:
    int dp[301][11];
    int solve(int i,vector<int> &diff,int d)
    {
        if(dp[i][d]!=-1)
            return dp[i][d];
        if(d==1)
        {
            int maxi=INT_MIN;
            for(int idx=i;idx<diff.size();idx++)
                maxi = max(maxi,diff[idx]);
            return dp[i][d]=maxi;
        }
        int maxi=INT_MIN;
        int ans = INT_MAX;
        for(int idx=i;idx<=diff.size()-d;idx++)
        {
            maxi=max(maxi,diff[idx]);
            ans = min(ans,maxi+solve(idx+1,diff,d-1));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& diff, int d) {
        memset(dp,-1,sizeof(dp));
        if(d>diff.size())
            return -1;
        return solve(0,diff,d);
    }
};