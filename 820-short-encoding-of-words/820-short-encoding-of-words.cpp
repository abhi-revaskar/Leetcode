class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i= 0;i<words.size();i++)
        {
            string w = words[i];
            if(mp.find(w)!=mp.end())
                continue;
            for(int j=0;j<w.size();j++)
            {
                mp[w.substr(j,w.size())]=i;
            }
        }
        unordered_set<int> s;
        for(auto x:words)
        {
            s.insert(mp[x]);
        }
        int ans=0;
        for(auto x:s)
        {
            ans+=words[x].length();
        }
        return ans+s.size();
    }
};