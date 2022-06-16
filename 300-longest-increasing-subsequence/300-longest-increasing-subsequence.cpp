class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> dp(nums.size(),1);
        // int ans = 1;
        // for(int i=1;i<nums.size();i++)
        // {
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if(nums[j]<nums[i])
        //             dp[i] = max(dp[i],dp[j]+1);
        //     }
        //     ans = max(ans,dp[i]);
        // }
        // return ans;
        vector<int> lis{nums[0]};
        for(int i=0;i<nums.size();i++)
        {
            if(lis.back()<nums[i])
                lis.push_back(nums[i]);
            else
            {
                int idx = lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
            
        }
        return lis.size();
    }
};