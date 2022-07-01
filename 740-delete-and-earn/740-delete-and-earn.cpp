class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        vector<int> dp(20001,0);
        dp[1] = mp[1];
        for(int i=2;i<dp.size();i++)
        {
            if(mp.find(i)==mp.end())
                dp[i]=dp[i-1];
            else
            {
                dp[i] = max(i*mp[i]+dp[i-2],dp[i-1]);
            }
        }
        return dp.back();
        
    }
};