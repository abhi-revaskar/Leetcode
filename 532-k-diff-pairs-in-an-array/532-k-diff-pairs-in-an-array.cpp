class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x:nums)
        {
            if(mp[x]!=0 && k!=0)
                continue;
            if(k==0 && mp[x]==1)
                ans++;
            else if(k!=0)
                ans+=mp[x-k]+mp[x+k];
            mp[x]++;
        }
        return ans;
    }
};