class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        t=s+"#"+t;
        vector<int> lps(t.length(),0);
        int i=1,p=0;
        while (i<t.length())
        {
            if(t[p]==t[i])
            {
                lps[i]=p+1;
                i++;p++;
            }
            else if(p==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                p=lps[p-1];
            }
        }
        t=s.substr(lps.back());
        reverse(t.begin(),t.end());
        return t+s;
    }
};