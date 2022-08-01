class Solution {
public:
    int solve(int i,vector<vector<pair<int,int>>> &adj,int thresh)
    {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> dist(adj.size(),INT_MAX);
        dist[i]=0;
        pq.push({0,i});
        while(!pq.empty())
        {
            int d = pq.top()[0],node=pq.top()[1];
            pq.pop();
            for(auto nbr:adj[node])
            {
                if(dist[nbr.first]>d+nbr.second)
                {
                    dist[nbr.first] = d+nbr.second;
                    pq.push({dist[nbr.first],nbr.first});
                }
            }
        }
        int cities = 0;
        for(auto x:dist)
            if(x<=thresh)
                cities++;
        return cities;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        int ans_node=0,mincities=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int nodes_at_thresh = solve(i,adj,distanceThreshold);
            if(nodes_at_thresh<=mincities)
            {
                mincities=nodes_at_thresh;
                ans_node=i;
            }
        }
        return ans_node;
        
    }
};