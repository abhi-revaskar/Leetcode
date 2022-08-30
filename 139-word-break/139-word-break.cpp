class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        unordered_set<string> set(w.begin(),w.end());
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j] && set.count(s.substr(j,i-j)))
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp.back();
    }
};