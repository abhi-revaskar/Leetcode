class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),0),v(graph.size(),0);
        queue<int> q;
        for(int i=0;i<graph.size();i++)
        {
            if(!v[i])
            {
                q.push(i);
                color[i]=1;
                v[i]=1;
                while(!q.empty())
                {
                    auto t = q.front();
                    for(auto x:graph[t])
                    {
                        if(color[x]==color[t])
                            return false;
                        if(!v[x])
                        {
                            q.push(x);
                            v[x]=1;
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