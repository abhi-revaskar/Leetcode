class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(auto x:s)
        {
            if(x!='#')
                st1.push(x);
            else if(!st1.empty())
                st1.pop();
        }
        for(auto x:t)
        {
            if(x!='#')
                st2.push(x);
            else if(!st2.empty())
                st2.pop();
        }
        if(st1.size()!=st2.size())
            return false;
        while(!st1.empty() && !st2.empty())
        {
            if(st1.top()!=st2.top())
                return false;
            st1.pop(),st2.pop();
        }
        return true;
    }
};