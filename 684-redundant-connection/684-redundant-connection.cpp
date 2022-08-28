class dsu{
    vector<int> par,rank;
    public:
    dsu(int n)
    {
        par.resize(n),rank.resize(n,1);
        for(int i=0;i<n;i++)
            par[i] = i;
    }
    void add(int i,int j)
    {
        int pari = find(i),parj = find(j);
        if(rank[pari]>rank[parj]) //rank = depth
            par[parj] = pari;
        else if(rank[pari]<rank[parj])
            par[pari] = parj;
        else
        {
            par[parj] = pari;
            rank[pari]++;
        }
    }
    int find(int x)
    {
        if(par[x]==x)
            return x;
        return par[x] = find(par[x]);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu *root = new dsu(edges.size()+1);
        for(auto x:edges)
        {
            if(root->find(x[0])==root->find(x[1]))
                return x;
            root->add(x[0],x[1]);
        }
        return {};
    }
};