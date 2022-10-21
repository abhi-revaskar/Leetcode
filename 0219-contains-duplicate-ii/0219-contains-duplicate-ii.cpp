class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0;i<=min(k,n-1);i++)
            s.insert(nums[i]);
        if(s.size()<=min(k,n-1))
            return true;
        for(int i=k+1;i<n;i++)
        {
            s.erase(nums[i-k-1]);
            s.insert(nums[i]);
            if(s.size()<=k)
                return true;
        }
        return false;
    }
};