class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int dp[5001][10];
    int solve(int n,int i)
    {
        if(dp[n][i]!=-1)
            return dp[n][i];
        if(n==1)
            return 1;
        long long ans = 0;
        for(auto x:mp[i])
            ans+=solve(n-1,x)%1000000007;
        return dp[n][i]=ans%1000000007;
    }
    int knightDialer(int n) {
        if(n==1)
            return 10;
        memset(dp,-1,sizeof(dp));
        mp = {{0,{4,6}},{1,{6,8}},{2,{7,9}},{3,{4,8}},{4,{0,3,9}},{6,{0,1,7}},{7,{2,6}},{8,{1,3}},{9,{2,4}}};
        long long ans = 0;
        for(auto x:mp)
        {
            for(auto y:x.second)
            ans+=solve(n-1,y)%1000000007;
        }
        return ans%1000000007;
    }
};