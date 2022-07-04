class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int delim = -1,ans=0;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.empty())
                {
                    ans = max(ans,i-delim-1);
                    delim = i;
                }
                else
                    st.pop();
            }
        } 
        int last_delim = s.length();
        while(!st.empty())
        {
            ans = max(ans,last_delim-st.top()-1);
            last_delim = st.top();
            st.pop();
        }
        ans = max(ans,last_delim-delim-1);        
        return ans;
    }
};