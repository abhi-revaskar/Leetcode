class Solution {
public:
    bool dfs(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &done)
    {
        vis[i] = 1;
        for(auto x:adj[i])
        {
            if(!vis[x] && dfs(x,adj,vis,done))
                return true;
            else if(vis[x] && !done[x]) 
                return true;
        }
        done[i] = 1;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto x:pre)
        {
            adj[x[1]].push_back(x[0]);
            ind[x[0]]++;
        }
        //dfs
        // vector<int> vis(n,0),done(n,0);
        // for(int i=0;i<n;i++)
        // {
        //     if(!vis[i] && dfs(i,adj,vis,done))
        //         return false;
        // }
        // return true;
        
        //bfs
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!ind[i])
                q.push(i);
        }
        while(!q.empty())
        {
            auto top = q.front();q.pop();
            for(auto x:adj[top])
            {
                ind[x]--;
                if(!ind[x])
                    q.push(x);
            }
        }
        for(auto x:ind)
            if(x!=0)
                return false;
        return true;
    }
};