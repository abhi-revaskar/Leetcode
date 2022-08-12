class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x:nums)
            s.insert(x);
        int ans = 0;
        for(auto x:nums)
        {
            if(s.count(x-1))
                continue;
            int cnt = 0,temp = x;
            while(s.count(temp))
            {
                cnt++;
                temp++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};