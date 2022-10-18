class Solution {
public:
    string solve(string &t)
    {
        int f=1;
        string ans;
        for(int i=1;i<t.length();i++)
        {
            if(t[i]==t[i-1])
                f++;
            else
            {
                ans+=to_string(f);
                ans+=t[i-1];
                f=1;
            }
        }
        ans+=to_string(f);
        ans+=t.back();
        return ans;
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string t = countAndSay(n-1);
        return solve(t);
    }
};