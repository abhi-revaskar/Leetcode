class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        stack<pair<char,int>> st;
        int i=0;
        while(i<s.length())
        {
            if(!st.empty() && st.top().second==k)
            {
                int kk = k;
                while(kk--)
                {
                    st.pop();
                }
            }
            else if(st.empty() || st.top().first!=s[i])
                st.push({s[i++],1});
            else
            {
                st.push({s[i++],st.top().second+1});
            }
        }
        while(!st.empty() && st.top().second==k)
        {
            int kk = k;
            while(kk--)
            {
                st.pop();
            }
        }
        while(!st.empty())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};