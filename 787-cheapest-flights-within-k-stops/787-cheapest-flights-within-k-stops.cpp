class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e8),temp;
        dist[src]=0;
        temp=dist;
        for(int i=0;i<=k;i++)
        {
            for(auto x:flights)
            {
                int u = x[0],v=x[1],w=x[2];
                if(temp[v]>dist[u]+w)
                    temp[v]=dist[u]+w;
            }
            dist=temp;
        }
        // for(auto x:dist)
        //     cout<<x<<" ";
        return (dist[dst]==1e8)?-1:dist[dst];
    }
};