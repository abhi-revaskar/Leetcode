class Solution {
public:
    int val(int i,int j,int m)
    {
        return (i*m+j);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        vector<vector<pair<int,int>>> adj(n*m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j<m-1)
                {
                    int u = val(i,j,m),v = val(i,j+1,m);
                    int w = abs(heights[i][j]-heights[i][j+1]);
                    adj[u].push_back({v,w});
                    adj[v].push_back({u,w});
                }
                if(i<n-1)
                {
                    int u = val(i,j,m),v = val(i+1,j,m);
                    int w = abs(heights[i][j]-heights[i+1][j]);
                    adj[u].push_back({v,w});
                    adj[v].push_back({u,w});
                }
            }
        }
        vector<int> dist(adj.size(),INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty())
        {
            int d = pq.top().first,node = pq.top().second;
            pq.pop();
            if(d>dist[node])
                continue;
            for(auto x:adj[node])
            {
                if(dist[x.first]>max(dist[node],x.second))
                {
                    dist[x.first] = max(dist[node],x.second);
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        return dist.back();
    }
};