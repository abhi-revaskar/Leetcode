class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(cnt!=0 || nums[i+1]<(i==0?INT_MIN:nums[i-1]) && nums[i]>(i==n-2?INT_MAX:nums[i+2]))
                    return 0;
                cnt++;
            }
        }
        return true;
    }
};