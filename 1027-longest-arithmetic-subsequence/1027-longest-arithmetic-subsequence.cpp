class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 1;
        vector<vector<int>> dp(1001,vector<int> (1001,1));
        for(int i = 0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int diff = nums[j] - nums[i]+500;
                dp[j][diff] = 1+dp[i][diff];
                ans = max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};