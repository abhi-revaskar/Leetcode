class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        unordered_map<string,int> mp;
        for(auto x:w)
        {
            mp[x]=1;
        }
        int dp[s.length()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1; //base condition
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==1) //if a valid segement ends here s[0..j]
                {
                    if(mp.find(s.substr(j,i-j))!=mp.end()) // if the substr s[j..i] is present in the dict
                    {
                        dp[i]=1;
                        break; // found a valid segment ending at this position.
                    }
                }
            }
        }
        return dp[s.length()];
    }
};