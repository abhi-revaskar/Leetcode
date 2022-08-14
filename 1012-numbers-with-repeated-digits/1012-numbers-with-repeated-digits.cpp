class Solution {
public:
    int dp[10][2][1024];
    int solve(int i,int tight,int seen,string &no)
    {
        if(i==no.length())
            return seen!=0;
        int &memo = dp[i][tight][seen];
        if(memo!=-1)
            return memo;
        int ans = 0,limit = tight?no[i]-'0':9;
        for(int digit=0;digit<=limit;digit++)
        {
            if((seen>>digit)&1)
                continue;
            int newseen = seen;
            if(seen || digit)
                newseen = seen | (1<<digit);
            if(tight && digit==limit)
                ans+=solve(i+1,1,newseen,no);
            else
                ans+=solve(i+1,0,newseen,no);
        }
        return memo = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string no = to_string(n);
        memset(dp,-1,sizeof(dp));
        int seen = 0,ans = 0;
        ans = solve(0,1,seen,no);
        return n-ans;
    }
};