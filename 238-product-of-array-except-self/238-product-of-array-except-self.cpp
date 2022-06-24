class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            ans[n-i-1] = nums[n-i-1] * ans[n-i];
        }
        int leftprod = 1;
        for(int i=0;i<n;i++)
        {
            ans[i] = leftprod * (i==n-1?1:ans[i+1]);
            leftprod *= nums[i];
        }
        return ans;
    }
};