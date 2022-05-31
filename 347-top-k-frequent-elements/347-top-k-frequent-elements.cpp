class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int> q1;
        priority_queue<pair<int,int>> q2;
        for(auto x:nums)
        {
          q1.push(x);
        }
        int t=q1.top();
        pair<int,int> p{0,t};
        while (!q1.empty())
        {
          if(q1.top()==t)
          {
            p.first++;
            q1.pop();
          }
          else
          {
            q2.push(p);
            p={1,q1.top()};
            t=q1.top();
            q1.pop();
          }
        }
        q2.push(p);
        vector<int> ans;
        while (k)
        {
          
          ans.push_back(q2.top().second);
          q2.pop();
          k--;
        }
        return ans;

    }
};