class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (2,1));
        int ans = 0;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(nums[j]>nums[i])
                    dp[i][1] = max(dp[i][1],1+dp[j][0]);
                else if(nums[j]<nums[i])
                    dp[i][0] = max(dp[i][0],1+dp[j][1]);
            }
            ans = max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};