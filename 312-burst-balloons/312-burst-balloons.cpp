class Solution {
public:
    int dp[302][302];
    int solve(int i,int j,vector<int> &nums)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        for(int k=i+1;k<j;k++)
        {
            ans = max(ans,solve(i,k,nums)+solve(k,j,nums)+nums[k]*nums[i]*nums[j]);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof(dp));
        return solve(0,nums.size()-1,nums);
        return 0;
    }
};