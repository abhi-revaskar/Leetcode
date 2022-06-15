class Solution {
public:
    static bool comp(string i,string j)
    {
        return i.length()<j.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int> dp;
        int ans=1;
        for(auto x:words)
        {
            dp[x]=1;
            for(int i=0;i<x.length();i++)
            {
                string t = x;
                t.erase(i,1);
                if(dp.find(t)!=dp.end())
                    dp[x]=max(dp[x],dp[t]+1);
            }
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};