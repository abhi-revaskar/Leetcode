class Solution {
public:
    unordered_set<string> set;
    vector<string> solve(string s,vector<string> &dict)
    {
        vector<string> ans;
        for(int idx = 0;idx<s.length();idx++)
        {
            string prefix = s.substr(0,idx+1);
            if(set.find(prefix)!=set.end())
            {
                if(idx==s.length()-1)
                {
                    ans.push_back(prefix);
                    return ans;
                }
                vector<string> temp = solve(s.substr(idx+1),dict);
                for(auto x:temp)
                {
                    ans.push_back(prefix+" "+x);
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        for(auto x:dict)
            set.insert(x);
        return solve(s,dict);
    }
};