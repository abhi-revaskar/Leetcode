class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        k = nums.size()-k;
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && k && st.top()>nums[i])
            {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while(k--)
            st.pop();
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};