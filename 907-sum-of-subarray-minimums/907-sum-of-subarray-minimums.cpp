class Solution {
    private:
    const int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse(arr.size()),nse(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                pse[i]=-1;
            else
                pse[i] = st.top();
            st.push(i);
        }
        st = stack<int> ();
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(st.empty())
                nse[i]=arr.size();
            else
                nse[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            ans+=(nse[i]-pse[i]-1)*1LL*arr[i] + arr[i]*1LL*(i-pse[i]-1)*(nse[i]-i-1);
            ans%=mod;
        }
        return ans;
    }
};