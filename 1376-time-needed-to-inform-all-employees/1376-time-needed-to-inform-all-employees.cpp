class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> time(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(headID);
        while(!q.empty())
        {
            int node = q.front();q.pop();
            for(auto x:adj[node])
            {
                time[x]+=time[node]+informTime[node];
                q.push(x);
            }
        }
        int ans = 0;
        for(auto x:time)
            ans = max(ans,x);
        return ans;
    }
};