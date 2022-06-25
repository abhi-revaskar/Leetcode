class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<time.size();i++)
        {
            time[i]%=60;
        }
        for(auto x:time)
        {
            if(mp.find((60-x)%60)!=mp.end())
                ans+=mp[(60-x)%60];
            mp[x]++;
        }
        return ans;
    }
};