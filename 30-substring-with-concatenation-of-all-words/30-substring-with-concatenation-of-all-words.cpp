class Solution {
public:
    bool check(int i,unordered_map<string,int> &mp1,string &s,vector<string> &w)
    {
        int k = w[0].length(),n=w.size();
        unordered_map<string,int> mp2;
        for(int j=i;j<i+n*k;j+=k)
        {
            string sub = s.substr(j,k);
            mp2[sub]++;
            if(mp1.count(sub)==0 || mp2[sub]>mp1[sub])
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp1;
        if(s.length()<words.size()*words[0].size())
            return {};
        for(auto x:words)
            mp1[x]++;
        vector<int> ans;
        for(int i=0;i<=s.size()-words.size()*words[0].size();i++)
        {
            if(check(i,mp1,s,words))
                ans.push_back(i);
        }
        return ans;
    }
};