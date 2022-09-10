class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0,len = 1;
        vector<int> dp(nums.size(),1),cnt(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        cnt[i] = cnt[j];
                        dp[i] = dp[j]+1;
                    }
                    else if(dp[i]==dp[j]+1)
                        cnt[i]+=cnt[j];
                }
            }
            // cout<<dp[i]<<" "<<cnt[i]<<endl;
            len = max(len,dp[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==len)
                ans+=cnt[i];
        }
        return ans;
    }
};