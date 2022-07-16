class Solution {
public:
    void solve(int i,vector<int> &path,vector<vector<int>> &ans,vector<vector<int>> &graph)
    {
        if(i==graph.size()-1)
        {
            path.push_back(i);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(i);
        for(auto x:graph[i])
            solve(x,path,ans,graph);
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,path,ans,graph);
        return ans;
    }
};