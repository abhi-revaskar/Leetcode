class Solution {
public:
    bool possible(vector<vector<pair<int,int>>> &adj,int k)
    {
        vector<int> vis(adj.size(),0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node==adj.size()-1)
                return true;
            for(auto x:adj[node])
            {
                if(!vis[x.first] && x.second<=k)
                {
                    vis[x.first]=1;
                    q.push(x.first);
                }
            }
        }
        return false;
    }
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
        int l = 0,h=1e6;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(possible(adj,mid))
                h=mid-1;
            else 
                l=mid+1;
        }
        return l;
    }
};