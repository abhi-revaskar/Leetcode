class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string t = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                t+=s[i];
            }
            else
            {
                if(!t.empty())
                {
                    st.push(t);
                    t="";
                }
            }
        }
        if(s[s.length()-1]!=' ')
        st.push(t);
        t="";
        while(!st.empty())
        {
            t+=st.top();
            st.pop();
            if(!st.empty())
                t+=' ';
        }
        return t;
    }
};