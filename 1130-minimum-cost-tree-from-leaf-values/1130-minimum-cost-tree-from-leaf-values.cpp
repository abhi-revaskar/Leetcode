class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> nge(arr.size()),pge(arr.size());
        stack<int> st;
        st.push(INT_MAX);
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(st.top()<arr[i])
                st.pop();
            nge[i] = st.top();
            st.push(arr[i]);
        }
        st = stack<int> ();
        st.push(INT_MAX);
        for(int i=0;i<arr.size();i++)
        {
            while(st.top()<=arr[i])
                st.pop();
            pge[i] = st.top();
            st.push(arr[i]);
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(nge[i]!=INT_MAX || pge[i]!=INT_MAX)
                ans+=min(nge[i],pge[i])*arr[i];
        }
        return ans;
    }
};