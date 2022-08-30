class Solution {
public:
    vector<int> manacher_odd(string &s)
    {
        string t;
        for(auto c:s)
        {
            t+=string("#")+c;
        }
        t+='#';
        t = '^'+t+'$';
        int n = t.length(),l=0,r=1;
        vector<int> d(n,0);
        for(int i=1;i<n;i++)
        {
            d[i] = min(d[l+r-i],r-i);
            //trivial algo
            while(t[i-d[i]]==t[i+d[i]])
                d[i]++;
            if(i+d[i]>r)
            {
                r = i+d[i];
                l = i-d[i];
            }
        }
        return vector<int> (d.begin()+1,d.end()-1);
    }
    string longestPalindrome(string s) {
        int n = s.length(),idx=0,len=1;
        vector<int> d = manacher_odd(s),d1(n),d2(n);
        for(int i=0;i<n;i++)
        {
            d1[i] = d[2*i+1]/2;
            d2[i] = (d[2*i]-1)/2;
            if(len<2*d1[i]-1)
            {
                len = 2*d1[i]-1;
                idx = i-d1[i]+1;
            }
            if(len<2*d2[i])
            {
                len = 2*d2[i];
                idx = i-d2[i];
            }
        }
        return s.substr(idx,len);
    }
};