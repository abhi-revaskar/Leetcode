class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q2;
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto x:nums)
        {
          m[x]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
          if(m[nums[i]]!=-1)
          {
            q2.push({m[nums[i]],nums[i]});
            m[nums[i]]=-1;
          }
        }
        while (k)
        {
          ans.push_back(q2.top().second);
          q2.pop();
          k--;
        }
        return ans;
    }
};