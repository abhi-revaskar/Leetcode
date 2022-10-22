class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        unordered_map<char,int> mp1,mp2;
        for(auto &x:t)
            mp1[x]++;
        int cnt = 0,start=0,len=INT_MAX,sz = mp1.size();
        // cout<<mp1.size()<<endl;
        while(r<s.length())
        {
            // cout<<l<<" "<<r<<endl;
            while(cnt<sz && r<s.length())
            {
                mp2[s[r]]++;
                if(mp1.count(s[r]) && mp2[s[r]]==mp1[s[r]])
                    cnt++;
                r++;
            }
            // cout<<l<<" "<<r<<endl;
            while(cnt==sz)
            {
                if(r-l<len)
                {
                    start = l;
                    len = r-l;
                }
                mp2[s[l]]--;
                if(mp1.count(s[l]) && mp2[s[l]]<mp1[s[l]])
                    cnt--;
                l++;
                // cout<<l<<" "<<r<<endl;
            }
        }
        if(len==INT_MAX)
            return "";
        return s.substr(start,len);
    }
};