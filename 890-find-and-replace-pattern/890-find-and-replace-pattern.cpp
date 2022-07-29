class Solution {
public:
    bool matches(string x,string p)
    {
        unordered_map<char,char> xtop,ptox;
        for(int i=0;i<p.length();i++)
        {
            if(xtop.count(x[i]) && xtop[x[i]]!=p[i])
                return false;
            if(ptox.count(p[i]) && ptox[p[i]]!=x[i])
                return false;
            xtop[x[i]]=p[i];
            ptox[p[i]]=x[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &x:words)
        {
            if(matches(x,pattern))
                ans.push_back(x);
        }
        return ans;
    }
};