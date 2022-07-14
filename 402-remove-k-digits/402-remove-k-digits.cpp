class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
            return "0";
        stack<int> st;
        st.push(0);
        for(int i=1;i<num.size();i++)
        {
            while(!st.empty() && num[st.top()]>num[i] && k)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k)
        {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=num[st.top()];
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans[0]=='0')
            ans = ans.substr(1);
        if(ans=="")
            return "0";
        return ans;
    }
};