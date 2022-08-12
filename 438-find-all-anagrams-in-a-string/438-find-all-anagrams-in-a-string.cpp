class Solution {
public:
    bool check(vector<int> &a,vector<int> &b)
    {
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length())
            return {};
        vector<int> mp1(26,0),mp2(26,0);
        vector<int> ans;
        for(int i=0;i<p.length();i++)
        {
            mp1[p[i]-'a']++;
            mp2[s[i]-'a']++;
        }
        if(check(mp1,mp2))
            ans.push_back(0);
        for(int i=p.length();i<s.length();i++)
        {
            mp2[s[i]-'a']++;
            mp2[s[i-p.length()]-'a']--;
            if(check(mp1,mp2))
                ans.push_back(i-p.length()+1);
        }
        return ans;
    }
};