class Solution {
public:
    int dp[101][10001];
    int solve(int k,int n)
    {
        if(dp[k][n]!=-1)
            return dp[k][n];
        if(k==1 || n==1 || n==0)
            return dp[k][n]= n;
        int ans = INT_MAX;
        int l=1,h=n,mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            int breaks=solve(k-1,mid-1);
            int doesnt = solve(k,n-mid);
            ans = min(ans,max(breaks,doesnt));
    
            if(breaks>doesnt)
                h=mid-1;
            else
                l=mid+1;
        }
        return dp[k][n]= ans+1;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};