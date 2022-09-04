class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> set;
        vector<int> ans;
        for(int i=0;i<k;i++)
            set.insert(nums[i]);
        ans.push_back(*set.begin());
        for(int l=0,r=k;r<nums.size();r++,l++)
        {
            set.erase(set.find(nums[l]));
            set.insert(nums[r]);
            ans.push_back(*set.begin());
        }
        return ans;
    }
};