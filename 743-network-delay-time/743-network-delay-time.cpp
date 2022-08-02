class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1000);
        dist[k]=0;
        for(int i=0;i<n;i++)
        {
            for(int edge=0;edge<times.size();edge++)
            {
                int u = times[edge][0];
                int v = times[edge][1];
                int w = times[edge][2];
                if(dist[v]>dist[u]+w)
                    dist[v]=dist[u]+w;
            }
        }
        int ans =INT_MIN;
        for(int i=1;i<=n;i++)
            ans = max(ans,dist[i]);
        return (ans==1000)?-1:ans;
    }
};