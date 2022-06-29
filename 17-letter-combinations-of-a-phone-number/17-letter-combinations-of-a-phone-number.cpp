class Solution {
public:
    unordered_map<int,string> mp;
    void find(int i,string &s,vector<string> &ans,string &digits)
    {
        if(i==digits.size() && !s.empty())
        {
            ans.push_back(s);
            return ;
        }
        for(auto x:mp[digits[i]-'0'])
        {
            s+=x;
            find(i+1,s,ans,digits);
            s.erase(s.length()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        string s;
        vector<string> ans;
        find(0,s,ans,digits);
        return ans;
    }
};