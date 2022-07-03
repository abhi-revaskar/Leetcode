class Solution {
public:
    unordered_set<string> set;
    vector<string> solve(int i,string s,vector<string> &dict)
    {
        vector<string> ans;
        for(int idx = i;idx<s.length();idx++)
        {
            string prefix = s.substr(i,idx-i+1);
            if(set.find(prefix)!=set.end())
            {
                if(idx==s.length()-1)
                {
                    ans.push_back(prefix);
                    return ans;
                }
                vector<string> temp = solve(0,s.substr(idx+1),dict);
                for(auto x:temp)
                {
                    ans.push_back(prefix+" "+x);
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& dict) {
        string ds = "";
        for(auto x:dict)
            set.insert(x);
        return solve(0,s,dict);
    }
};