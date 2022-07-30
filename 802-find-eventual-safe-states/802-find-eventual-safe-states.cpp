class Solution {
public:
    void solve(int i,vector<int> &vis,vector<int> &trav,vector<int> &safe,vector<vector<int>>& graph)
    {
        vis[i]=1;
        for(auto x:graph[i])
        {
            if(!vis[x])
                solve(x,vis,trav,safe,graph);
            else if(!trav[x])
                safe[i] = 0;
            if(safe[x]==0)
                safe[i]=0;
        }
        trav[i]=1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0),trav(n,0),safe(n,1),ans;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                solve(i,vis,trav,safe,graph);
        }
        for(int i=0;i<n;i++)
        {
            if(safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};