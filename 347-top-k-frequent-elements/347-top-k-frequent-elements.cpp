class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        vector<vector<int>> mp(nums.size()+1);
        for(auto x:nums)
        {
          m[x]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
          if(m[nums[i]]!=-1)
          {
            mp[m[nums[i]]].push_back(nums[i]);
            m[nums[i]]=-1;
          }
        }
        int c=0;
        for (int i = nums.size(); i >=0 ; i--)
        {
          if(mp[i].size())
          {
            for (int j = 0; j < mp[i].size(); j++)
            {
              if(c==k)
              break;
              ans.push_back(mp[i][j]);
              c++;
            }
            if(c==k)
            break;
          }
        }
        
        return ans;
    }
};