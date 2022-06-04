class Solution {
public:
    int romanToInt(string s) {
    int n=s.length();
    int ans=0;
        unordered_map<char,int> mp{{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='I')
            {
                // cout<<"i";
                if(i<n-1 && (s[i+1]!='V' && s[i+1]!='X'))
                ans+=1;
                else if(i<n-1)
                {
                    ans+=mp[s[i+1]]-1;
                    i++;
                }
                else
                ans++;
            }
            else if(s[i]=='X')
            {
                // cout<<"x";
                if(i<n-1 && (s[i+1]!='L' && s[i+1]!='C'))
                ans+=mp[s[i]];
                else if(i<n-1)
                {
                    ans+=mp[s[i+1]]-mp[s[i]];
                    i++;
                }
                else
                ans+=mp[s[i]];
            }
            else if(s[i]=='C')
            {
                // cout<<"c";
                if(i<n-1 && (s[i+1]!='D' && s[i+1]!='M'))
                ans+=mp[s[i]];
                else if(i<n-1)
                {
                    ans+=mp[s[i+1]]-mp[s[i]];
                    i++;
                }
                else
                ans+=mp[s[i]];
            }
            else
            {
                // cout<<"z";
                ans+=mp[s[i]];
            }
        }
        return ans;

    }
};