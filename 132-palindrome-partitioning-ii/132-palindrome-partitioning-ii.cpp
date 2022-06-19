class Solution {
public:
    int dp[2001];
   bool pal(int i,int j,string &s)
   {
       while(i<=j)
       {
           if(s[i]!=s[j])
               return false;
           i++;j--;
       }
       return true;
   }
    int solve(int i,string &s)
    {
        if(dp[i]!=-1)
            return dp[i];
        if(i==s.length()-1)
            return 0;
         if(i==s.length())
            return -1;
        int t=s.length();
        for(int j=i;j<s.length();j++)
        {
            if(pal(i,j,s))
            {
                t=min(t,solve(j+1,s));
            }
        }
        dp[i]=t+1;
        return dp[i];
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
        
    }
};