class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> idx;
        for(int i=0;i<nums2.size();i++)
        {
            idx[nums2[i]]=i;
        }
        vector<int> ans,nge(nums2.size());
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<nums2[i])
                st.pop();
            if(st.empty())
                nge[i]=-1;
            else
                nge[i]=st.top();
            st.push(nums2[i]);
        }
        for(auto &x:nums1)
            ans.push_back(nge[idx[x]]);
        return ans;
    }
};