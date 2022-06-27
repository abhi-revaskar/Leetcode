class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = INT_MIN;
        stack<int> st;
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty() && h[st.top()]>h[i])
            {
                int ht = h[st.top()];
                st.pop();
                ans = max(ans,ht*(i-(st.empty()?-1:st.top())-1));
            }
            st.push(i);
        }
        int n = h.size();
        while(!st.empty())
        {
            int ht = h[st.top()];
            st.pop();
            ans = max(ans,ht*(n-(st.empty()?-1:st.top())-1));
        }
        return ans;
    }
};