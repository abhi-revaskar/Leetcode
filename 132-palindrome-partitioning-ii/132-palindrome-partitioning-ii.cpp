class Solution {
public:
    int dp[2001],pdp[2001][2001];
   bool pal(int l,int h,string &s)
   {
       int i=l,j=h;
       if(pdp[i][j]!=-1)
           return pdp[l][h];
       while(i<=j)
       {
           if(s[i]!=s[j])
               return pdp[l][h] =false;
           i++;j--;
       }
       return pdp[l][h] = true;
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
                t=min(t,1+solve(j+1,s));
            }
        }
        return dp[i]=t;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        memset(pdp,-1,sizeof(pdp));
        return solve(0,s);
        
    }
};