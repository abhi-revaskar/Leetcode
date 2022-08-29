class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n,1000000),temp;
        dp[src] = 0;
        temp = dp;
        for(int i=0;i<=k;i++)
        {
            int f = 0;
            for(auto x:flights)
            {
                int u = x[0],v=x[1],w=x[2];
                if(dp[u]+w<temp[v])
                {
                    temp[v] = min(temp[v],dp[u]+w);
                    f =  1;                    
                }
            }
            dp = temp;
            if(!f)
                break;
        }
        if(dp[dst]==1000000)
            return -1;
        return dp[dst];
    }
};