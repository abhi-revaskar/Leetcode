class Solution {
public:
    static bool comp(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> ans;
        unordered_map<string,int> mp;
        for(auto &x:words)
            mp[x]++;
        for(auto &x:mp)
        {
            ans.push_back({x.second,x.first});
        }
        sort(begin(ans),end(ans),comp);
        // reverse(begin(ans),end(ans));
        vector<string> ret;
        for(int i=0;i<k;i++)
            ret.push_back(ans[i].second);
        return ret;
    }
};