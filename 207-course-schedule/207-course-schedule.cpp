class Solution {
public:
    bool dfs(vector<vector<int>> &g,vector<int> &t,vector<int> &v,int node)
    {
        v[node]=1;
        for (auto x : g[node]) {
            if(x==node)
                return false;
            if(v[x]==1 && t[x]==0)
                return false;
            if (v[x]==0 && !dfs(g, t, v, x)) 
                return false;
        }
        t[node]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        vector<int> v(numCourses,0),t(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(v[i]==0 && !dfs(g,t,v,i))
                return false;
        }
        return true;
    }
};
