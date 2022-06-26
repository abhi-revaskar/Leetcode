class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        if(nums.size()<2)
            return 0;
        int i=0,j=1;
        while(i<nums.size()-1 && j<nums.size())
        {
            if(i>=j)
                j=i+1;
            if(i>0 && nums[i]==nums[i-1])
                i++;
            else if(nums[i]+k == nums[j])
            {
                ans++;
                i++;j++;
            }
            else if(nums[i]+k > nums[j])
                j++;
            else 
                i++;
        }
        return ans;
    }
};