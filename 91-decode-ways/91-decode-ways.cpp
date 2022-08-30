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
        // memset(dp,-1,sizeof(dp));
        // return solve(0,s);
        int next2 = 1,next1 = 1,n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            int curr = check(i,1,s)*next1+check(i,2,s)*next2;
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};