class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> row,col;
    int solve(pair<int,int> node,unordered_map<int,unordered_set<int>> &seen)
    {
        int ans = 1;
        queue<pair<int,int>> q;
        q.push(node);
        seen[node.first].insert(node.second);
        while(!q.empty())
        {
            auto top =q.front();q.pop();
            for(auto t:row[top.second])
            {
                if(seen[t.first].count(t.second)==0)
                {
                    seen[t.first].insert(t.second);
                    ans++;
                    q.push(t);
                }
            }
            for(auto t:col[top.first])
            {
                if(seen[t.first].count(t.second)==0)
                {
                    seen[t.first].insert(t.second);
                    ans++;
                    q.push(t);
                }
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,unordered_set<int>> seen;
        for(auto x:stones)
        {
            pair t = {x[0],x[1]};
            row[x[1]].push_back(t);
            col[x[0]].push_back(t);
        }
        int ans = 0;
        for(auto x:stones)
        {
            pair t = {x[0],x[1]};
            if(seen[t.first].count(t.second)==0)
                ans += solve(t,seen)-1;
        }
        return ans;
    }
};