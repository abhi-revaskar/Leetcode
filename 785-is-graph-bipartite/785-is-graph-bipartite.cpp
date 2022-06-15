class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &color,int i)
    {
        for(auto x:graph[i])
        {
            if(color[x]==color[i])
                return false;
            if(!color[x])
            {
                color[x]=-color[i];
                if(!dfs(graph,color,x))
                    return false;
            }
                
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0);
        // for(int i = 0;i<graph.size();i++)
        // {
        //     if(!color[i])
        //     {
        //         color[i]=1;
        //         if(!dfs(graph,color,i))
        //             return false;
        //     }
        // }
        // return true;
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            if(!color[i])
            {
                q.push(i);
                color[i]=1;
                while(!q.empty())
                {
                    auto t = q.front();
                    for(auto x:graph[t])
                    {
                        if(color[x]==color[t])
                            return false;
                        if(!color[x])
                        {
                            q.push(x);
                            color[x]=-color[t];
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};