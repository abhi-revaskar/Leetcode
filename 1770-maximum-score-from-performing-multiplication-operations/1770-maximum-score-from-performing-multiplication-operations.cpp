class Solution {
    const long long off = 1e9;
public:
    // unordered_map<int,unordered_map<int,int>> dp;
    long long dp[1001][1001];
    long long solve(int i,int k,int m,vector<int> &nums,vector<int> &mul)
    {
        int j = nums.size()-1-k+i;
        if(dp[i][k]!=-1)
            return dp[i][k];
        if(k==m-1)
        {
            return dp[i][k] = max(mul[k]*1LL*nums[i],mul[k]*1LL*nums[j])+off;
        }
        return dp[i][k] = off+max(solve(i+1,k+1,m,nums,mul)+mul[k]*1LL*nums[i],solve(i,k+1,m,nums,mul)+mul[k]*1LL*nums[j]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(),m=multipliers.size();
        memset(dp,-1,sizeof(dp));
        long long ans = solve(0,0,m,nums,multipliers);
        ans = ans-(off*1LL*m);
        return ans;
    }
};