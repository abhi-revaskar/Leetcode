class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:times)
            adj[edge[0]].push_back({edge[1],edge[2]});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        q.push({0,k});
        while(!q.empty())
        {
            int node = q.top()[1],wt = q.top()[0];
            q.pop();
            if(wt>dist[node])
                continue;
            for(auto nbrs:adj[node])
            {
                if(dist[nbrs.first]>wt+nbrs.second)
                {
                    dist[nbrs.first] = wt+nbrs.second;
                    q.push({dist[nbrs.first],nbrs.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<dist.size();i++)
            ans = max(ans,dist[i]);
        return (ans==INT_MAX)?-1:ans;
    }
};