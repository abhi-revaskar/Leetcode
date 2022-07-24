class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(mid>0 && nums[mid]>nums[mid-1] && mid<nums.size()-1 && nums[mid]>nums[mid+1])
                return mid;
            if(mid == 0)
            {
                if(mid==nums.size()-1 || nums[mid]>nums[mid+1])
                    return mid;
            }
            if(mid == nums.size()-1)
            {
                if(mid==0 || nums[mid]>nums[mid-1])
                    return mid;
            }
            if(nums[mid]<nums[mid+1])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
};