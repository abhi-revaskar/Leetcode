class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        stack<int> st;
        st.push(nums2[m-1]);
        unordered_map<int,int> mp;
        mp[nums2[m-1]]=-1;
        for (int i = m-2; i >=0; i--)
        {
          if(nums2[i]<st.top())
          {
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
          }
          else
          {
            while (!st.empty()&& st.top()<nums2[i])
            {
              st.pop();
            }
            if(st.empty())
            {
              mp[nums2[i]]=-1;
              st.push(nums2[i]);
            }
            else
            {
              mp[nums2[i]]=st.top();
              st.push(nums2[i]);
            }
          }
        }
        for (int i = 0; i < n; i++)
        {
          ans.push_back(mp[nums1[i]]);
        }
        return ans;
        
}
};