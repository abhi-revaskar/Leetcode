class dsu{
    public:
    vector<int> par,rank;
    dsu(int n)
    {
        par.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
            par[i] = i;
    }
    void add(int a,int b)
    {
        int par_a = find(a);
        int par_b = find(b);
        if(rank[par_a]==rank[par_b])
        {
            rank[par_a]++;
            par[par_b] = par_a;
        }
        else if(rank[par_a]>rank[par_b])
        {
            par[par_b] = par_a;
        }
        else
            par[par_a] = par_b;
    }
    int find(int n)
    {
        if(par[n]==n)
            return n;
        return par[n] = find(par[n]);
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        dsu *obj = new dsu(26);
        for(auto x:equations)
        {
            if(x[1]=='=')
            {
                obj->add(x[0]-'a',x[3]-'a');
            }
        }
        for(auto x:equations)
        {
            if(x[1]=='!' && obj->find(x[0]-'a')==obj->find(x[3]-'a'))
                return false;
        }
        return true;
    }
};