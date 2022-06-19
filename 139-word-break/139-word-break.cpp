class Solution {
public:
    unordered_map<string,int> mp;
    int dp[301][301];
    bool solve(int i,int j,string s,unordered_map<string,int> &mp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==j)
            return mp.find(s.substr(i,1))!=mp.end();
        if(mp.find(s.substr(i,j-i+1))!=mp.end())
            return true;
        bool ans=0;
        for(int k=i;k<j;k++)
        {
            bool t = solve(i,k,s,mp) && solve(k+1,j,s,mp);
            ans = ans || t;
        }
        return dp[i][j] = ans;
    }
    bool wordBreak(string s, vector<string>& w) {
        memset(dp,-1,sizeof(dp));
        for(auto x:w)
        {
            mp[x]=1;
        }
        return solve(0,s.size()-1,s,mp);
    }
};