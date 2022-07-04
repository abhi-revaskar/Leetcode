class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> delim;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                    delim.push_back(i);
                else
                    st.pop();
            }
        } 
        while(!st.empty())
        {
            delim.push_back(st.top());
            st.pop();
        }
        sort(delim.begin(),delim.end());
        if(delim.size()==0)
            return s.length();
        delim.push_back(s.length());
        int ans = delim[0];
        for(int i=1;i<delim.size();i++)
            ans = max(ans,delim[i]-delim[i-1]-1);
        return ans;
    }
};