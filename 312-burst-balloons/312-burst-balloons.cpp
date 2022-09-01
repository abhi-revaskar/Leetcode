class Solution {
public:
    int dp[303][303];
    int solve(int i,int j,vector<int> &nums)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        for(int k=i+1;k<j;k++)
        {
            int coins = nums[i]*nums[k]*nums[j];
            ans = max(ans,coins+solve(i,k,nums)+solve(k,j,nums));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        return solve(0,n-1,nums);
    }
};