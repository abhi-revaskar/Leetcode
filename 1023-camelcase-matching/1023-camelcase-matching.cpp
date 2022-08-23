class Solution {
public:
    bool match(string s,string t)
    {
        int n = s.length(), m = t.length();
        if(s.length()<t.length())
            return false;
        int i=0,j=0;
        while(i<n || j<m)
        {
            while(i<n && s[i]>='a' && s[i]<='z')
                i++;
            while(j<m && t[j]>='a' && t[j]<='z')
                j++;
            if(i==n && j==m)
                return true;
            if(j==m || i==n)
                return false;
            while(i<n && j<m)
            {
                if(s[i]==t[j])
                {i++;j++;}
                else if(s[i]>='a' && s[i]<='z')
                    i++;
                else
                    return false;
            }
            // if(j<m && t[j]>='a' && t[j]<='z')
            //     return false;
            // if(i<n && s[i]>='A' && s[i]<='Z')
            //     return false;
        }
        return true;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto x:queries)
        {
            if(match(x,pattern))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};