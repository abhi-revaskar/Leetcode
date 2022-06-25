class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto x:time)
        {
            
            if(mp.find((60-x%60)%60)!=mp.end())
                ans+=mp[(60-x%60)%60];
            mp[x%60]++;
        }
        return ans;
    }
};