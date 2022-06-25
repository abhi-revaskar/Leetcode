class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==2)
            return nums[0];
        int i=0,j=0;
        do{
            i = nums[i];
            j = nums[nums[j]];
        }while(i!=j);
        i=0;
        while(i!=j)
        {
            i=nums[i];
            j=nums[j];
        }
        return i;
    }
};