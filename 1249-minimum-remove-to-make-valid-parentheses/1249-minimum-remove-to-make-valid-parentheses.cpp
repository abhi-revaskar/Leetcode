class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> pars;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                pars.push_back(i);
            else if(s[i]==')')
            {
                if(pars.empty() || s[pars.back()]!='(')
                    pars.push_back(i);
                else
                    pars.pop_back();
            }
        }
        string ans = "";
        // cout<<pars.back();
        for(int i=s.length()-1;i>=0;i--)
        {
            if(!pars.empty() && i==pars.back())
                pars.pop_back();
            else
                ans+=s[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};