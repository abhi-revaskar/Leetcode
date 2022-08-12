class Solution {
public:
    bool check(unordered_map<char,int> &mp1,unordered_map<char,int> &mp2)
    {
        for(auto x:mp1)
            if(mp2[x.first]<x.second)
                return false;
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length()<t.length())
            return "";
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<t.length();i++)
        {
            mp1[t[i]]++;
        }
        int imin=-1,jmin=s.length(),i=0,j=0;
        while(j<s.length())
        {
            mp2[s[j]]++;
            if(mp2.size()>=mp1.size() && check(mp1,mp2))
            {
                // cout<<i<<" "<<j<<endl;
                if((j-i)<(jmin-imin))
                {
                    jmin = j;
                    imin = i;
                }
                mp2[s[i]]--;
                mp2[s[j]]--;
                i++;
            }
            else
                j++;
        }
        if(imin==-1)
            return "";
        return s.substr(imin,jmin-imin+1);
    }
};