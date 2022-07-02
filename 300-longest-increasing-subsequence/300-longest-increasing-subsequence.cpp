class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> is;
        is.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++)
        {
            if(is.back()<nums[i])
                is.push_back(nums[i]);
            else
                // cout<<upper_bound(is.begin(),is.end(),nums[i])-is.begin();
                is[lower_bound(is.begin(),is.end(),nums[i])-is.begin()]=nums[i];
        }
        return is.size();
    }
};