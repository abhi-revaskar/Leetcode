class Solution {
public:
    int match(string &s,string &w,int i)
    {
        int cnt = 0;
        for(int j=i;j<s.length();j+=w.length())
        {
            for(int idx = 0;idx<w.length();idx++)
            {
                if(w[idx]!=s[j+idx])
                    return cnt;
            }
            cnt++;
        }
        return cnt;
    }
    int maxRepeating(string s, string w) {
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            ans = max(ans,match(s,w,i));
        }
        return ans;
    }
};