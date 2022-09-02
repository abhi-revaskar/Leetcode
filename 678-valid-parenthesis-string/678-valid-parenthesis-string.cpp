class Solution {
public:
    bool checkValidString(string s) {
        int stars = 0;
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            char x = s[i];
            if(x=='*')
                stars++;
            else if(x=='(')
                st.push(i);
            else
            {
                if(st.size())
                    st.pop();
                else if(stars==0)
                    return 0;
                else
                    stars--;
            }
        }
        // reverse(s.begin(),s.end());
        st = stack<int> ();
        stars = 0;
        for(int i=s.length()-1;i>=0;i--)
        {
            char x = s[i];
            if(x=='*')
                stars++;
            else if(x==')')
                st.push(i);
            else
            {
                if(st.size())
                    st.pop();
                else if(stars==0)
                    return 0;
                else
                    stars--;
            }
        }
        return true;
        // cout<<st.top()<<" "<<s.length();
        stars = 0;
        int opens = st.size(),i=s.length()-1;
        while(opens)
        {
            if(s[i]=='*')
                stars++;
            else if(s[i]=='(')
                opens--;
            i--;
        }
        return stars>=st.size();
    }
};