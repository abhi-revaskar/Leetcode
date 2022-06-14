class Solution {
public:
    bool dfs(vector<vector<int>> &g,vector<bool> &todo,vector<bool> &done,int node)
    {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!dfs(g, todo, done, v)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);
        vector<bool> v(numCourses,false),t(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!v[i] && !dfs(graph,t,v,i))
                return false;
        }
        return true;
    }
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
};
