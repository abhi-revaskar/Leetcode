class Solution {
public:
    vector<int> find(string t)
    {
        int n = t.length();
        int l = 0,r = 0;
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
    string removeOccurrences(string s, string part) {
        while(true)
        {
            vector<int> z = find(part+"$"+s);
            // cout<<s<<endl;
            string next;
            int p = part.length(),j=s.length();
            for(int i=p+1;i<z.size();i++)
            {
                // cout<<s[i-p-1]<<" "<<z[i]<<endl;
                if(z[i]!=p)
                    next+=s[i-p-1];
                else
                {
                    j = i-1;
                    break;
                }
            }
            for(int i=j;i<s.length();i++)
                next+=s[i];
            if(s.length()==next.length())
                return s;
            s = next;
        }
        return s;
    }
};