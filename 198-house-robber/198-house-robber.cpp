class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> profit(nums.size()+1);
        profit[0]=0;
        profit[1]=nums[0];
        for(int i =2;i<=nums.size();i++)
        {
            profit[i]=max(nums[i-1]+profit[i-2],profit[i-1]);
        }
        return profit.back();
    }
};