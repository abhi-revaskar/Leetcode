class Solution {
public:
    int dp[102][102];
    int solve(int i,int j,int l,int r,vector<int> &cuts){
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(l==r)
            return 0;
        int ans = INT_MAX;
        for(int k=l;k<r;k++)
        {
            ans = min(ans,solve(i,cuts[k],l,k,cuts)+solve(cuts[k],j,k+1,r,cuts)+j-i);
        }
        return dp[l][r]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,n,0,cuts.size(),cuts);
    }
};