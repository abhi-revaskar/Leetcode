class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis{nums[0]};
        int ans = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(lis.back()<nums[i])
            {
                lis.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[idx] = nums[i];
            }
            ans = max(ans,int(lis.size()));
        }
        return ans;
    }
};