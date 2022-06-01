class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> mx(nums.size(),-1);
        int n=nums.size();
        st.push(nums[n-1]);
        for(int i=2*nums.size()-2;i>=0;i--)
        {
          if(st.top()>nums[i%n])
          {
            mx[i%n]=st.top();
            st.push(nums[i%n]);
          }
          else
          {
            while (!st.empty() && st.top()<=nums[i%n])
            {
              st.pop();
            }
            if(st.empty())
            {
              mx[i%n]=-1;
              st.push(nums[i%n]);
            }
            else
            {
              mx[i%n]=st.top();
              st.push(nums[i%n]);
            }
          }
        }
        
        return mx;
        

    }
};