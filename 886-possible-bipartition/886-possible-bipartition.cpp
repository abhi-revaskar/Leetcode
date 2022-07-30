class Solution {
public:
    bool bfs(int i,vector<int> &color,vector<vector<int>> &adj)
    {
        color[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();q.pop();
            for(auto x:adj[node])
            {
                if(color[x]==color[node])
                    return true;
                if(color[x]==0)
                {
                    color[x]=-color[node];
                    q.push(x);
                }
            }
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto x:dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> color(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0 && bfs(i,color,adj))
                return false;
        }
        return true;
    }
};