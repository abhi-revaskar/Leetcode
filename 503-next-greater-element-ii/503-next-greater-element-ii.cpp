class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> mx(nums.size(),-1);
        int idx,high=INT_MIN;
        for (int  i = 0; i < nums.size(); i++)
        {
          if(nums[i]>high)
          {
            idx=i;
            high=nums[i];
          }
        }
        int final_idx=idx;
        st.push(high);
        idx--;
        while (idx>=0)
        {
          if(st.top()>nums[idx])
          {
            mx[idx]=st.top();
            st.push(nums[idx]);
          }
          else
          {
            while (!st.empty() && st.top()<=nums[idx])
            {
              st.pop();
            }
            if(st.empty())
            {
              mx[idx]=-1;
              st.push(nums[idx]);
            }
            else
            {
              mx[idx]=st.top();
              st.push(nums[idx]);
            }
          }
          idx--;
        }
        idx=nums.size()-1;
        while (final_idx<idx)
        {
          if(st.top()>nums[idx])
          {
            mx[idx]=st.top();
            st.push(nums[idx]);
          }
          else
          {
            while (!st.empty() && st.top()<=nums[idx])
            {
              st.pop();
            }
            if(st.empty())
            {
              mx[idx]=-1;
              st.push(nums[idx]);
            }
            else
            {
              mx[idx]=st.top();
              st.push(nums[idx]);
            }
          }
          idx--;
        }
        return mx;
        

    }
};