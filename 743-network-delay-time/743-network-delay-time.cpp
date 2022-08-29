class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1000000);
        dist[k] = 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:times)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto top = pq.top();pq.pop();
            int u = top.second;
            for(auto nbr:adj[u])
            {
                // if(dist[u]!=top.first)
                //     cout<<u<<" "<<dist[u]<<endl;
                int v = nbr.first, w = nbr.second;
                if(top.first+w<dist[v])
                {
                    dist[v] = top.first + w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
            ans = max(ans,dist[i]);
        return ans==1000000?-1:ans;
    }
};