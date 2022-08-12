class Solution {
public:
    bool check(unordered_map<char,int> &mp1,unordered_map<char,int> &mp2)
    {
        for(auto x:mp1)
            if(mp2[x.first]!=x.second)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        unordered_map<char,int> mp1,mp2;
        for(auto x:s1)
            mp1[x]++;
        for(int i=0;i<s1.length();i++)
        {
            mp2[s2[i]]++;
        }
        if(check(mp1,mp2))
            return true;
        for(int i=s1.length();i<s2.length();i++)
        {
            mp2[s2[i-s1.length()]]--;
            mp2[s2[i]]++;
            if(check(mp1,mp2))
                return true;
        }
        return false;
    }
};