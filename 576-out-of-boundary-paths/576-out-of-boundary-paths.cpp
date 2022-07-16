class Solution {
    private:
    const int mod = 1e9+7;
    int dp[51][51][51];
public:
    Solution()
    {
        memset(dp,-1,sizeof(dp));
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        if(maxMove==0 || startRow<0 || startRow>=m || startColumn<0 ||startColumn>=n)
            return 0;
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        long long ans = 0;
        if(startRow == 0)
            ans++;
        if(startRow == m-1)
            ans++;
        if(startColumn == 0)
            ans++;
        if(startColumn == n-1)
            ans++;
        ans+=findPaths(m,n,maxMove-1,startRow-1,startColumn)%mod;
        ans+=findPaths(m,n,maxMove-1,startRow+1,startColumn)%mod;
        ans+=findPaths(m,n,maxMove-1,startRow,startColumn-1)%mod;
        ans+=findPaths(m,n,maxMove-1,startRow,startColumn+1)%mod;
        return dp[startRow][startColumn][maxMove] = ans%mod;
    }
};