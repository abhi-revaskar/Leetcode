class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                nums[i]=0;
        }
        for(int i=0 ;i<nums.size();i++)
        {
            int n = abs(nums[i]);
            if(n>0 && n<=nums.size())
                if(nums[n-1]!=0)
                    nums[n-1] = -(abs(nums[n-1]));
            else
                 nums[n-1] = -n;
        }
        for(auto x:nums)
            cout<<x<<" ";
        for(int i=1;i<=nums.size();i++)
            if(nums[i-1]>=0)
                return i;
        return nums.size()+1;
    }
};