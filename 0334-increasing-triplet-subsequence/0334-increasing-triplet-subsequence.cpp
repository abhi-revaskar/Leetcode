class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for(auto x:nums)
        {
            if(lis.back()<x)
                lis.push_back(x);
            else
            {
                int idx = lower_bound(begin(lis),end(lis),x)-begin(lis);
                lis[idx] = x;
            }
            if(lis.size()==3)
                return true;
        }
        return false;
    }
};