class Solution {
    map<char,int> mp;
public:
    char low()
    {
        for(auto x:mp)
            if(x.second)
                return x.first;
        return 'a';
    }
    string robotWithString(string s) {
        for(auto x:s)
            mp[x]++;
        string ans,st;
        for(auto x:s)
        {
            // cout<<x<<":";
            // cout<<st<<" "<<ans<<endl;
            st+=x;
            mp[x]--;
            while(!st.empty() && low()>=st.back())
            {
                ans+=st.back();
                st.pop_back();
            }
        }
        while(!st.empty())
        {
            ans+=st.back();
            st.pop_back();
        }
        return ans;
    }
};