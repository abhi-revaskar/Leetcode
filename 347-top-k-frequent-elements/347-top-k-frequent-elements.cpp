class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x:nums)
            freq[x]++;
        vector<vector<int>> mp(nums.size()+1);
        for(auto x:freq)
            mp[x.second].push_back(x.first);
        vector<int> ans;
        for(int i=mp.size()-1;i>=0;i--)
        {
            for(auto x:mp[i])
            {
                if(k)
                {
                    ans.push_back(x);
                    k--;
                }
                else
                    break;
                
            }
        }
        return ans;
    }
};