class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;
        int n=heights.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
          while(!st.empty() && heights[st.top()]>heights[i])
          {
            int h=heights[st.top()];
            st.pop();
            ans=max(ans,(i-(st.empty()?-1:st.top())-1)*h);
          }
          st.push(i);
        }
        while(!st.empty())
          {
            int h=heights[st.top()];
            st.pop();
            ans=max(ans,(n-(st.empty()?-1:st.top())-1)*h);
          }
        return ans;
    }
};