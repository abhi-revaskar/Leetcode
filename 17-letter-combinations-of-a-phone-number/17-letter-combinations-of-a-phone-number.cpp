class Solution {
unordered_map<char,string> mp;
public:
    void solve(int i,string &s,vector<string> &ans,string &digits)
    {
        if(i==digits.size())
        {
            ans.push_back(s);
            return;
        }
        for(auto c:mp[digits[i]])
        {
            s+=c;
            solve(i+1,s,ans,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        string s;
        solve(0,s,ans,digits);
        return ans;
    }
};