class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for(auto x:nums)
            s.insert(x);
        for(auto x:nums)
        {
            if(s.count(x-1)==0)
            {
                int cnt=0;
                while(s.count(x))
                {
                    cnt++;
                    x++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
        
    }
};