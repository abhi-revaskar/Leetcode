class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto x:wordDict)
            set.insert(x);
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==1 && set.find(s.substr(j,i-j))!=set.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        // for(auto x:dp)
        //     cout<<x<<" ";
        return dp[s.size()];
    }
};