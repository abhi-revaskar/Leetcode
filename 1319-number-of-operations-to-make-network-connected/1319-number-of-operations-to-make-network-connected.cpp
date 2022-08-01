class Solution {
public:
    void solve(int i,int par,int &cables,vector<int> &vis,vector<int> & done,vector<vector<int>> &adj)
    {
        vis[i]=1;
        for(auto x:adj[i])
        {
            if(!vis[x])
                solve(x,i,cables,vis,done,adj);
            else if(x!=par && !done[x])
                cables++;
        }
        done[i]=1;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int comps=0,cables=0;
        vector<int> vis(n,0),done(n,0);
        vector<vector<int>> adj(n);
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                comps++;
                solve(i,-1,cables,vis,done,adj);
            }
        }
        // cout<<comps<<" "<<cables<<endl;
        if(comps-1>cables)
            return -1;
        return comps-1;
    }
};