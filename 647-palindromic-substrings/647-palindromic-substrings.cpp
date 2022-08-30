class Solution {
public:
    vector<int> manacher_odd(string &s)
    {
        string t;
        for(auto c:s)
            t+=string("#")+c;
        t+='#';
        t = '^'+t+'$';
        int n = t.length(),l=0,r=1;
        vector<int> d(n);
        for(int i=1;i<n;i++)
        {
            d[i] = min(r-i,d[l+r-i]);
            while(t[i-d[i]]==t[i+d[i]])
                d[i]++;
            if(i+d[i]>r)
            {
                r = i+d[i];
                l = i-d[i];
            }
        }
        return vector<int> (begin(d)+1,end(d)-1);
    }
    int countSubstrings(string s) {
        int n = s.length(),ans = 0;
        vector<int> d = manacher_odd(s);
        for(int i=0;i<n;i++)
        {
            ans+=d[2*i+1]/2;
            ans+=(d[2*i]-1)/2;
        }
        return ans;
    }
};