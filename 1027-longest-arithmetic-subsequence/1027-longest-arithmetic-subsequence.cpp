class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 1;
        vector<vector<int>> dp(1001,vector<int> (1001,1));
        for(int i = 0;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int diff = nums[i] - nums[j]+500;
                dp[i][diff] =max(dp[i][diff],1+dp[j][diff]);
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};