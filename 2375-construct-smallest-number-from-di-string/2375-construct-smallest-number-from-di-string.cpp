class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "1";
        for(auto x:pattern)
            ans+='1';
        int maxi = 1;
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='I')
            {
                ans[i+1] = '0'+maxi+1;
                maxi++;
            }
            else
            {
                int j=i;
                while(j>0 && pattern[j-1]=='D')
                {
                    ans[j]++;
                    maxi = max(maxi,ans[j]-'0');
                    j--;
                }
                if(j>=0)
                {
                    ans[j]++;
                    maxi = max(maxi,ans[j]-'0');
                }
                ans[i+1] = ans[i]-1;
            }
        }
        return ans;
    }
};