class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> set;
        vector<int> ans;
        int start;
        for(auto x:adjacentPairs)
        {
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        for(auto x:mp)
            if(x.second.size()==1)
                start=x.first;
        ans.push_back(start);
        set.insert(start);
        while(ans.size()!=mp.size())
        {
            int t= start;
            for(auto x:mp[t])
            {
                if(set.count(x)==0)
                {
                    ans.push_back(x);
                    set.insert(x);
                    start=x;
                }
            }
        }
        // for(auto x:ans)
        //     cout<<x<<" ";
        return ans;
        
    }
};