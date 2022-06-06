class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        return "1";

        string t=countAndSay(n-1);
        string ans="";
        for (int i = 0; i < t.length(); i++)
        {
            int cnt=1;
            while (i<t.length()-1 && t[i+1]==t[i])
            {
                cnt++;
                i++;
            }
            ans+=to_string(cnt)+t[i];
        }
        
        return ans;
    }
};