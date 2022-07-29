class Solution {
public:
    double eva(string a,string b,string par,unordered_map<string,unordered_map<string,double>> &adj,unordered_map<string,int> &seen)
    {
        // cout<<a<<" "<<b<<endl;
        seen[a]=1;
        for(auto x:adj[a])
        {
            if(x.first==par || seen[x.first])
                continue;
            // cout<<x.first<<" "<<x.second<<" ";
            if(x.first==b)
                return x.second;
            double ans = eva(x.first,b,a,adj,seen);
            // cout<<a<<" "<<b<<" "<<ans<<endl;
            if(ans!=-1.0)
                return (adj[a][x.first])*ans;
        }
        return -1.0;        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> adj;
        unordered_set<string> vars;
        for(int i=0;i<equations.size();i++)
        {
            string a = equations[i][0],b = equations[i][1];
            adj[a][b] = values[i];
            adj[b][a] = 1.0/values[i];
            // cout<<a<<" "<<b<<endl;
            vars.insert(a);
            vars.insert(b);
        }
        vector<double> ans;
        for(auto x:queries)
        {
            if(vars.count(x[0])==0 || vars.count(x[1])==0)
                ans.push_back(-1);
            else if(x[0]==x[1])
                ans.push_back(1.0);
            else if(adj[x[0]].count(x[1]))
                ans.push_back(adj[x[0]][x[1]]);
            else if(adj[x[1]].count(x[0]))
                ans.push_back(1.0/adj[x[1]][x[0]]);
            else
            {
                unordered_map<string,int> seen;
                ans.push_back(eva(x[0],x[1],x[0],adj,seen));
            }
        }
        return ans;
    }
};