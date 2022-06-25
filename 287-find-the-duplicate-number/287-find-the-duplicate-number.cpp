class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==2)
            return nums[0];
        int i=nums[0],j=nums[nums[0]];
        while(i!=j)
        {
            i = nums[i];
            j = nums[nums[j]];
        }
        i=0;
        while(i!=j)
        {
            i=nums[i];
            j=nums[j];
        }
        return i;
    }
};