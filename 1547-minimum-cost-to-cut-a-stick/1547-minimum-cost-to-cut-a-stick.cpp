class Solution {
public:
    int dp[102][102];
    int solve(int i,int j,vector<int> &cuts)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i+1==j)
            return dp[i][j] = 0;
        int ans = INT_MAX;
        for(int idx= i+1;idx<j;idx++)
        {
            int left = solve(i,idx,cuts);
            int right = solve(idx,j,cuts);
            ans = min(ans,left+right);
        }
        
        return dp[i][j] = ans+cuts[j]-cuts[i];
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        return solve(0,cuts.size()-1,cuts);
    }
};