class Solution {
public:
    int dp[101][10001];
    int superEggDrop1(int k, int n) {
        if(dp[k][n]!=-1)
            return dp[k][n];
        if(n==1 || k==1 || n==0)
            return dp[k][n] = n;
        int ans = INT_MAX;
        int l=1,h=n,mid;
        while(l<=h)
        {
            mid = (l+h)/2;
            int t1=superEggDrop1(k-1,mid-1); //egg broke
            int t2=superEggDrop1(k,n-mid); //egg not broke
            int t = 1+max(t1,t2);
            ans=min(ans,t);
            if(t1<t2)
                l=mid+1;
            else
                h=mid-1;
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return superEggDrop1(k,n);
    }
};