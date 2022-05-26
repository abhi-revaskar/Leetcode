class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int mid;
        while (l<=h)
        {
          mid=(l+h)/2;
          if(nums[mid]==target)
          return mid;
          if(nums[l]<=nums[mid]) //left half is sorted
          {
            if(nums[l]<=target && nums[mid]>=target) //target is present in left half
            {
              h=mid-1;
            }
            else //target is not present in left half
            {
              l=mid+1;
            }
          }
          else //right half is sorted
          {
            if(nums[mid]<=target && nums[h]>=target) //target is present in right half
            {
              l=mid+1;
            }
            else //target is not present in right half
            {
              h=mid-1;
            }
          }
        }
        return -1;
    }
};