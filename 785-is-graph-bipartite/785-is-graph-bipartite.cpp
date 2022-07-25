class Solution {
public:
    bool bfs(int x,vector<int> &color,vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(x);
        color[x]=1;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(auto x:graph[top])
            {
                if(color[x]==color[top])
                    return false;
                if(color[x]==0)
                {
                    color[x]=-color[top];
                    q.push(x);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);
        for(int i=0;i<color.size();i++)
            if(color[i]==0 && !bfs(i,color,graph))
                return false;
        return true;    
    }
};