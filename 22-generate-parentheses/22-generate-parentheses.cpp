class Solution {
public:
    void solve(int n,int opening,string &ds,vector<string> &ans)
    {
        if(ds.size()==2*n)
        {
            ans.push_back(ds);
            return;
        }
        if(opening<n)
        {
            ds+='(';
            solve(n,opening+1,ds,ans);
            ds.erase(ds.size()-1);
        }
        if(opening*2!=ds.size())
        {
            ds+=')';
            solve(n,opening,ds,ans);
            ds.erase(ds.size()-1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds ="";
        solve(n,0,ds,ans);
        return ans;
    }
};