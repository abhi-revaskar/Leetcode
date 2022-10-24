class Solution {
public:
    int ans = 0;
    void solve(int i,set<char> &st,vector<string>& t)
    {
        if(i==t.size())
        {
            ans = max(ans, int(st.size()));
            return;
        }
        
        solve(i+1,st,t);
        for(auto x:t[i])
        {
            if(st.count(x))
                return;
        }
        for(auto x:t[i])
            st.insert(x);
        solve(i+1,st,t);
        for(auto x:t[i])
            st.erase(x);
    }
    int maxLength(vector<string>& arr) {
        set<char> st;
        vector<string> t;
        for(auto s:arr)
        {
            set<char> st;
            for(auto c:s)
                st.insert(c);
            if(st.size()==s.length())
                t.push_back(s);
        }
        // memset(dp,-1,sizeof(dp));
         solve(0,st,t);
        return ans;
    }
};
