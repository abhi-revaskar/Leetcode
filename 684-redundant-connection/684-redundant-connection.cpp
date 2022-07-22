class dsu{
    public:
    vector<int> par,rank;
    dsu(int n){
        par.resize(n+1,0);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int find(int node)
    {
        if(par[node]==node)
            return node;
        return par[node] = find(par[node]);
    }
    void add(int a,int b)
    {
        int apar = find(a);
        int bpar = find(b);
        if(rank[apar]>=rank[bpar])
        {
            par[bpar] = apar;
            rank[apar]+=rank[bpar];
        }
        else
        {
            par[apar] = bpar;
            rank[bpar]+=rank[apar];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu* obj = new dsu(n);
        vector<int> ans;
        for(auto &x:edges)
        {
            if(obj->find(x[0])==obj->find(x[1]))
            {
                ans = x;
                break;
            }
            else
                obj->add(x[0],x[1]);
        }
        return ans;
    }
};