class Solution {
public:
    bool match(string s,string t)
    {
        int n = s.length(),m = t.length();
        for(int i=n;i<m;i+=n)
        {
            for(int j = 0;j<n;j++)
                if(s[j]!=t[i+j])
                    return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        if(s.length()==1)
            return false;
        for(int i=1;i<=s.length()/2;i++)
        {
            if(s.length()%i==0 && match(s.substr(0,i),s))
                return true;
        }
        return false;
    }
};