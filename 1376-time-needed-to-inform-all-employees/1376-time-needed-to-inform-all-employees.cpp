class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,INT_MAX);
        dist[headID]=0;
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back({i,informTime[manager[i]]});
        }
        int ans = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,headID});
        while(!pq.empty())
        {
            int d = pq.top()[0],node=pq.top()[1];
            pq.pop();
            for(auto x:adj[node])
            {
                if(dist[x.first]>d+x.second)
                {
                    dist[x.first] = d+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
                ans = max(ans,dist[i]);
        }
        return ans;
        
    }
};