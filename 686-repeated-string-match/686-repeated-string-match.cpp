class Solution {
public:
    vector<int> z_func(string &s)
    {
        int n = s.length(),l=0,r=0;
        // cout<<n;
        vector<int> z(n,0);
        for(int i = 1;i<n;i++)
        {
            z[i] = max(0,min(z[i-l],r-i+1));
            while(i+z[i]<n && s[z[i]]==s[i+z[i]])
                z[i]++;
            if(i+z[i]-1>r)
            {
                r = i+z[i]-1;
                l = i;
            }
        }
        return z;
    }
    int repeatedStringMatch(string a, string b) {
        int n = b.length(),m=a.length();
        string t;
        // cout<<m;
        for(int i=0;i<(2*n+2*m-1)/m;i++)
        {
            t+=a;
        }
        // cout<<t<<endl;
        string s = b+"#"+t;
        auto z = z_func(s);
        for(int i = 0;i<t.length();i++)
        {
            int k = z[i+b.length()+1];
            // cout<<k<<" ";
            if(k==b.length())
                return ((i+k+m-1)/m);
        }
        return -1;
    }
};