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
        for(int i=nums.size()-1;i>0;i--)
        {
          int tidx=i-(nums.size()-idx);
          if(tidx<0)
          tidx+=nums.size();
          if(st.top()>nums[tidx])
          {
            mx[tidx]=st.top();
            st.push(nums[tidx]);
          }
          else
          {
            while (!st.empty() && st.top()<=nums[tidx])
            {
              st.pop();
            }
            if(st.empty())
            {
              mx[tidx]=-1;
              st.push(nums[tidx]);
            }
            else
            {
              mx[tidx]=st.top();
              st.push(nums[tidx]);
            }
          }
        }
        
        return mx;
        

    }
};