class Solution {
public:
    unordered_set<string> set;
    unordered_map<string,vector<string>> dp;
    vector<string> solve(string s,vector<string> &dict)
    {
        if(dp.find(s)!=dp.end())
            return dp[s];
        vector<string> ans;
        for(int idx = 0;idx<s.length();idx++)
        {
            string prefix = s.substr(0,idx+1);
            if(set.find(prefix)!=set.end())
            {
                if(idx==s.length()-1)
                {
                    ans.push_back(prefix);
                    return dp[s] = ans;
                }
                vector<string> temp = solve(s.substr(idx+1),dict);
                for(auto x:temp)
                {
                    ans.push_back(prefix+" "+x);
                }
            }
        }
        return dp[s] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        for(auto x:dict)
            set.insert(x);
        return solve(s,dict);
    }
};