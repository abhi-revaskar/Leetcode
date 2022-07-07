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
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3);
           
    }
};