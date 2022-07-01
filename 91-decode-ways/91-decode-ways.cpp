class Solution {
public:
    int dp[101];
    int solve(string s)
    {
        if(dp[s.size()]!=-1)
            return dp[s.size()];
        int n = s.size();
        // cout<<s<<endl;
        if(s.length()<3)
        {
            if(s=="0" || s=="" || s[0] =='0')
                return 0;
            if(stoi(s)>0 && stoi(s)<=10 || stoi(s)==20)
                return 1;
            if(stoi(s)>=11 && stoi(s)<=19 || stoi(s)>20 && stoi(s)<=26)
                return 2;
        }
        int ans = 0;
        if(s.back()!='0')
        ans += solve(s.substr(0,n-1));
        if(stoi(s.substr(n-2))>9 && stoi(s.substr(n-2))<=26)
            ans += solve(s.substr(0,n-2));
        return dp[s.size()]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s);
    }
};