class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            mini=min(mini,nums[i]);
        }
        return ans-nums.size()*mini;
    }
};