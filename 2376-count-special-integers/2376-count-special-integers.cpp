class Solution {
public:
    int dp[11][2][2000];
    int solve(int i,int restricted,string &n,int seen,int num)
    {
        if(i==n.length())
        {
            // cout<<num<<endl;
            return num!=0;
        }
        if(dp[i][restricted][seen]!=-1)
            return dp[i][restricted][seen];
        int ans = 0;
        int limit = (restricted?n[i]-'0':9);
        for(int digit=0;digit<=limit;digit++)
        {
            if((seen>>digit)&1)
                continue;
            if(seen || digit)
                seen = (seen | (1<<digit));
            if(restricted && digit == limit)
                ans+=solve(i+1,1,n,seen,num*10+digit);
            else
                ans+=solve(i+1,0,n,seen,num*10+digit);
            seen = (seen &(~(1<<digit)));
        }
        return dp[i][restricted][seen] = ans;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int seen = 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,1,s,seen,0);
    }
};