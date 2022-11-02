class Solution {
public:
    int solve(string st,string end,unordered_set<string> &s)
    {
        if(st==end)
            return 0;
        int ans = 1000;
        vector<char> v{'A','C','G','T'};
        for(int i=0;i<8;i++)
        {
            for(auto x:v)
            {
                if(x!=st[i])
                {
                    string t = st;
                    t[i] = x;
                    if(s.count(t))
                    {
                        s.erase(t);
                        ans = min(ans,solve(t,end,s));
                        s.insert(t);
                    }
                }
            }
        }
        return ans+1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        for(auto &x:bank)
        {
            s.insert(x);
        }
        if(s.count(end)==0)
            return -1;
        int ans = solve(start,end,s);
        if(ans>10)
            return -1;
        return ans;
            
    }
};