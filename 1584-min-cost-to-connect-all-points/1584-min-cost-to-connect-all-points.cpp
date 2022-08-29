class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});                    
            }
        }
        int ans = 0,cnt=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,0});
        vector<bool> vis(n,0);
        // vis[0]=1;
        while(cnt!=n)
        {
            auto top = pq.top();pq.pop();
            if(vis[top.second])
                continue;
            vis[top.second] = 1;
            cnt++;
            ans-=top.first;
            for(auto nbr:adj[top.second])
            {
                if(!vis[nbr.first])
                    pq.push({-nbr.second,nbr.first});
            }
        }
        return ans;
    }
};
 