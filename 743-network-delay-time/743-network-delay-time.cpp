class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long long> dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=0;i<n;i++)
        {
            int f = 0;
            for(auto edge:times)
            {
                int u = edge[0],v = edge[1],w = edge[2];
                if(dist[u]+w<dist[v])
                {
                    dist[v] = dist[u] + w;
                    f = 1;
                }
            }
            if(!f)
                break;
        }
        long long ans = INT_MIN;
        for(int i=1;i<=n;i++)
            ans = max(ans,dist[i]);
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};