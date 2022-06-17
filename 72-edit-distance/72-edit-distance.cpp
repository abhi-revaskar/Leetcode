class Solution {
public:
    
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(w1[i-1]==w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
            return dp[n][m];
    }
};