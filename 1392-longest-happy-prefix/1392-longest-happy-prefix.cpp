class Solution {
public:
    vector<int> z_func(string &s)
    {
        vector<int> z(s.length(),0);
        int l=0,r=0;
        for(int i=1;i<s.length();i++)
        {
            z[i] = max(0,min(z[i-l],r-i+1));
            while(i+z[i] < s.length() && s[z[i]]==s[i+z[i]])
                z[i]++;
            if(i+z[i]-1>r)
            {
                r = i+z[i]-1;
                l = i;
            }
        }
        return z;
    }
    string longestPrefix(string s) {
        auto z = z_func(s);
        for(int i=1;i<s.length();i++)
        {
            if(i+z[i]==s.length())
                return s.substr(i);
        }
        return "";
    }
};