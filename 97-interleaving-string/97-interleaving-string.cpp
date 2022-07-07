class Solution {
public:
    int dp[101][101];
    int solve(string s1,string s2,string s3)
    {
        if(dp[s1.length()][s2.length()]!=-1)
            return dp[s1.length()][s2.length()];
        if((s1.length()+s2.length())!=s3.length())
            return dp[s1.length()][s2.length()] = false;
        if(s1=="" && s2=="" && s3=="")
            return dp[s1.length()][s2.length()]=true;
        if(s1[0]!=s3[0] && s2[0]!=s3[0])
            return dp[s1.length()][s2.length()]=false;
        bool ans = false;
        if(s1[0]==s3[0])
            ans = ans || solve(s1.substr(1),s2,s3.substr(1));
        if(s2[0]==s3[0])
            ans = ans || solve(s1,s2.substr(1),s3.substr(1));
        return dp[s1.length()][s2.length()]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // memset(dp,-1,sizeof(dp));
        // return solve(s1,s2,s3);
        if((s1.length()+s2.length())!=s3.length())
            return false;
        int n = s1.length(),m=s2.length();
        vector<int> prev(m+1,0),dp(m+1,0);
        prev[m] = 1;
        for(int i=m-1;i>=0;i--)
        {
            if(s3[n+i]==s2[i])
                prev[i]=prev[i+1];
        }
        for(int i=n-1;i>=0;i--)
        {
            dp[m]=((s3[m+i]==s1[i])?prev[m]:0);
            for(int j=m-1;j>=0;j--)
            {
            
                dp[j]=0;
                if(s1[i]==s3[j+i])
                    dp[j]=dp[j]||prev[j];
                if(s2[j]==s3[j+i])
                    dp[j]=dp[j]||dp[j+1];
            }
            prev=dp;
        }
        return prev[0];
    }
};