class Solution {
public:
    bool pal(string &s)
    {
        int n = s.length();
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    void solve(int i,vector<string> &ds,vector<vector<string>> &ans,string &s)
    {
        if(i==s.length())
        {
            ans.push_back(ds);
            return ;
        }
        string t;
        for(int j=i;j<s.length();j++)
        {
            t+=s[j];
            if(pal(t))
            {
                ds.push_back(t);
                solve(j+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,ds,ans,s);
        return ans;
    }
};