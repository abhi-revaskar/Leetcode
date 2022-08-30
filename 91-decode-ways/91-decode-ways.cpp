class Solution {
public:
    int dp[101];
    bool check(int i,int n,string &s)
    {
        if(n>s.length())
            return 0;
        if(n==1)
            return s[i]!='0';
        if(i==s.length()-1)
            return 0;
        int code = stoi(s.substr(i,2));
        return code>9 && code<27;
    }
    int solve(int i,string &s)
    {
        // cout<<i<<endl;
        if(i>=s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = check(i,1,s)*solve(i+1,s)+check(i,2,s)*solve(i+2,s);
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};