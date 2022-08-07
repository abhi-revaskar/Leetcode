class Solution {
    private:
    int mod = 1e9+7;
public:
    long long dp[5][20001];
    long long solve(int i,int n)
    {
        if(dp[i][n]!=-1)
            return dp[i][n];
        if(n==1)
        {
            if(i==0 || i==4)
                return 1;
            if(i==1 || i==3)
                return 2;
            return 4;
        }

        if(i==0)
            return dp[i][n] = solve(1,n-1);
        if(i==1)
            return dp[i][n] = (solve(0,n-1)+solve(2,n-1))%mod;
        if(i==2)
            return dp[i][n] = (solve(0,n-1)+solve(1,n-1)+solve(3,n-1)+solve(4,n-1))%mod;
        if(i==3)
            return dp[i][n] = (solve(2,n-1)+solve(4,n-1))%mod;
        return dp[i][n] = solve(0,n-1)%mod;
        
    }
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        long long ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<5;i++)
        {
            ans+=solve(i,n-1)%mod;
        }
        return ans%mod;
    }
};