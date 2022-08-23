class Solution {
public:
    vector<int> z_func(string &s)
    {
        vector<int> z(s.length(),0);
        int l=0,r=0;
        for(int i=1;i<s.length();i++)
        {
            z[i] = max(0,min(z[i-l],r-i+1));
            while(i+z[i]<s.length() && s[z[i]]==s[i+z[i]])
                z[i]++;
            if(i+z[i]-1>r)
            {
                r = i+z[i]-1;
                l = i;
            }
        }
        return z;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        s = s+s;
        int n = s.length();
        s = goal+"#"+s;
        auto z = z_func(s);
        for(int i = 0;i<n;i++)
        {
            int k = z[i+goal.length()+1];
            if(k==goal.length())
                return true;
        }
        return false;
    }
};