class Solution {
public:
    int rob(vector<int>& nums) {
        int far =0;
        int near=nums[0];
        for(int i =2;i<=nums.size();i++)
        {
            int curr =max(nums[i-1]+far,near);
            far = near;
            near = curr;
        }
        return near;
    }
};