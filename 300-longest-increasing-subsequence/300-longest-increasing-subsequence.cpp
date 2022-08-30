class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        int n = nums.size(),ans = 1;
        for(int i=1;i<n;i++)
        {
            if(lis.back()<nums[i])
                lis.push_back(nums[i]);
            else
            {
                int idx= lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                lis[idx] = nums[i];
            }
            ans = max(ans,int(lis.size()));
        }
        return ans;
    }
};