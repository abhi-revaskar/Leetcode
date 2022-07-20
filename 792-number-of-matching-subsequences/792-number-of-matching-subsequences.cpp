class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<string>> mp;
        int ans = 0;
        for(auto &x:words)
        {
            mp[x[0]].push_back(x);
        }
        for(auto &x:s)
        {
            auto curr = mp[x];
            mp[x].clear();
            for(auto &y:curr)
            {
                if(y.length()==1)
                    ans++;
                else
                {
                    string temp = y.substr(1);
                    mp[temp[0]].push_back(temp);
                }
            }
        }
        return ans;
    }
};