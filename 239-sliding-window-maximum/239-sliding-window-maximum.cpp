class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
          while (!dq.empty() && dq.back()<nums[i])
          {
            dq.pop_back();
          }
          dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        int l=0,r=k;
        while (r<nums.size())
        {
          if(nums[l]==dq.front())
          {
            dq.pop_front();
          }
          while (!dq.empty() && dq.back()<nums[r])
          {
            dq.pop_back();
          }
          dq.push_back(nums[r]);
          ans.push_back(dq.front());
          r++;
          l++;
        }
        return ans;
    }
};