class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> mp,remtonum;
        for(auto x:nums)
        {
            mp[x%space]++;
            if(remtonum.count(x%space))
                remtonum[x%space] = min(remtonum[x%space],x);
            else
                remtonum[x%space] = x;
                             
        }
        int mx=0,ans;
        for(auto x:mp)
        {
            if(x.second>mx)
            {
                mx = x.second;
                ans = remtonum[x.first];
            }
            else if(x.second==mx)
                ans = min(ans,remtonum[x.first]);
        }
        return ans;
    }
};