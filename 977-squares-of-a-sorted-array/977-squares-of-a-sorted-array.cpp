class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int j = i-1;
        while(j>=0 && i<nums.size())
        {
            if(-nums[j]<=nums[i])
                ans.push_back(nums[j]*nums[j--]);
            else
                ans.push_back(nums[i]*nums[i++]);
        }
        while(j>=0)
            ans.push_back(nums[j]*nums[j--]);
        while(i<nums.size())
            ans.push_back(nums[i]*nums[i++]);
        return ans;
    }
};