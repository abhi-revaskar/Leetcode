class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60,0);
        int ans = 0;
        for(auto x:time)
        {
            ans+=v[(60-x%60)%60];
            v[x%60]++;
        }
        return ans;
    }
};