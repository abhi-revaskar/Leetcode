class Solution {
public:
    vector<int> z_func(string &t)
    {
        int l = 0,r=0,n=t.length();
        vector<int> z(n,0);
        for(int i=1;i<n;i++)
        {
            z[i] = max(0,min(z[i-l],r-i+1));
            while(i+z[i]<n && t[z[i]]==t[i+z[i]])
                z[i]++;
            if(i+z[i]-1>r)
            {
                r = i+z[i]-1;
                l = i;
            }
        }
        return z;
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        t = s +"#"+t;
        auto z = z_func(t);
        int n = z.size();
        string add;
        for(int i=0;i<n;i++)
        {
            if(i+z[i] == n)
            {
                add = s.substr(z[i]);
                break;
            }
        }
        reverse(add.begin(),add.end());
        add = add +s;
        return add;
    }
};