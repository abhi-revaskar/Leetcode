class Solution {
public:
    int dp[10001];
    int solve(vector<int> &nums,int i)
    {
        if(dp[i]!=-1)
            return dp[i];
        if(i==nums.size()-1)
            return 0;
        int n = nums.size();
        int ans = 10001;
        if(nums[i]==0)
            return dp[i]=ans;
        for(int j=1;j<=min(nums[i],n-i-1);j++)
            ans = min(ans,1+solve(nums,i+j));
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};