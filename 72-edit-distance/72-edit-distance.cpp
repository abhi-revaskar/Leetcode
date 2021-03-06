class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,0));
        for(int i = 0;i<=word1.size();i++)
        {
            dp[i][0]=i;
            for(int j = 1;j<=word2.size();j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(word1[i-1]!=word2[j-1])
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp.back().back();
    }
};