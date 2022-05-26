class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        if (n==1)
        {
          return nums[0];
        }
        int mid;
        while (l<=h)
        {
          mid=(l+h)/2;
          if(mid-1<0)
          {
            return nums[mid];
          }
          else if(mid+1>=n)
          {
            return nums[mid];
          }
          else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
          {
            return nums[mid];
          }
          else if(nums[mid]==nums[mid-1])
          {
            if((h-mid)%2==0)
            {
              h=mid-2;
            }
            else
            {
              l=mid+1;
            }
          }
          else
          {
            if((h-mid-1)%2==0)
            {
              h=mid-1;
            }
            else
            {
              l=mid+2;
            }
          }
        }
        return -1;
    }
};