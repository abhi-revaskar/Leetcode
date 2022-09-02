class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n%k)
            return false;
        unordered_map<int,int> mp;
        for(auto &x:nums)
            mp[x]++;
        for(auto &x:nums)
        {
            if(mp[x])
            {
                for(int i=x;i<x+k;i++)
                {
                    if(mp[i]==0)
                        return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};