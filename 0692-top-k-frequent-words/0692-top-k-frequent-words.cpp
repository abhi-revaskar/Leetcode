class Compare
{
public:
    bool operator() (pair<int,string> &a, pair<int,string> &b)
    {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};
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
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> pq;
        for(auto &x:mp)
        {
            pq.push({x.second,x.first});
            // cout<<"added "<<x.first<<endl;
            // cout<<pq.top().second<<endl;
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> ret;
        while(!pq.empty())
        {
            // cout<<pq.top().second<<endl;
            ret.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(ret),end(ret));
        return ret;
    }
};