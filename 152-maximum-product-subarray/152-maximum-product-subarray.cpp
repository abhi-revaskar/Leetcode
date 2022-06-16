class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN,mx=1,mn=1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                mx = max(mx*nums[i],nums[i]);
                mn = min(mn*nums[i],nums[i]);
                ans = max(ans,mx);
            }
            else if(nums[i]<0)
            {
                int t = mx;
                mx = max(mn*nums[i],nums[i]);
                mn = min(t*nums[i],nums[i]);
                ans = max(ans,mx);
            }
            else
            {
                mx = mn = 1;
                ans = max(ans, 0);
            }
        }
        return ans;
    }
};