class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        priority_queue<pair<int,char>> q;
        for(auto x:mp)
        {
            q.push({x.second,x.first});
        }
        string ans = "";
        auto prev = q.top();
        q.pop();
        ans+=prev.second;
        prev.first--;
        while(!q.empty())
        {
            auto top = q.top();
            q.pop();
            ans+=top.second;
            top.first--;
            if(prev.first)
            {
                q.push({prev.first,prev.second});
            }
            prev = top;
        }
        if(prev.first && ans.back()==prev.second)
            return "";
        return ans;
        
    }
};