class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(h==0)
            return nums[0];
        if(nums[0]<nums[h])
            return nums[0];
        int mid;
        while (l<=h)
        {
            
            mid=(l+h)/2;
            if(mid< nums.size()-1 && nums[mid]>nums[mid+1])
              return nums[mid+1];
            if(mid>0 && nums[mid-1]>nums[mid])
                return nums[mid];
            if(nums[0]<nums[mid])
                l=mid+1;
            else
            {
                h=mid-1;
            }
        }
        return -1;
    }
};