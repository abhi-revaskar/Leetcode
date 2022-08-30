class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int ans1, prev2 = 0,prev1 = nums[0];
        for(int i=1;i<n-1;i++)
        {
            int curr = max(prev1,nums[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        ans1 = prev1,prev2 = 0,prev1 = nums[1];
        for(int i=2;i<n;i++)
        {
            int curr = max(prev1,nums[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(ans1,prev1);
    }
};