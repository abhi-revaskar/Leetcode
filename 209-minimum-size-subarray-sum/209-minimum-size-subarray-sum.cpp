class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum[i] = sum[i-1] + nums[i];
        }
        int l=0,r = 0,ans = INT_MAX;
        while(r<nums.size())
        {
            if(sum[r]-(l>0?sum[l-1]:0)>=target)
            {
                ans = min(ans,r-l+1);
                l++;
            }
            else
                r++;
        }
        return ans==INT_MAX?0:ans;
    }
};