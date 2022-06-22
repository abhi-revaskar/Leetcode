class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> q2; //min heap for k  largest elements
      for (int i = 0; i < n; i++)
      {
        if(q2.size()<k)
            q2.push(nums[i]);
          else if(q2.top()<nums[i])
          {
              q2.pop();
              q2.push(nums[i]);
          }
      }
        return q2.top();
      
    }
};