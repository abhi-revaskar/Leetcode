class DSU{
    public:
    vector<int> rank,parent;
    DSU()
    {
        rank.resize(26,1);
        parent.resize(26);
        for(int i=0;i<26;i++)
            parent[i]=i;
    }
    int find(int n)
    {
        if(parent[n]==n)
            return n;
        return parent[n]=find(parent[n]);
    }
    void add(int a,int b)
    {
        int par_a = find(a);
        int par_b = find(b);
        if(rank[par_a]>rank[par_b])
        {
            parent[par_b] = par_a;
        }
        else if(rank[par_a]<rank[par_b])
        {
            parent[par_a] = par_b;
        }
        else
        {
            parent[par_b] = par_a;
            rank[par_a]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU *obj = new DSU();
        for(auto x:equations)
        {
            if(x[1]=='=')
                obj->add(x[0]-'a',x[3]-'a');
        }
        for(auto x:equations)
        {
            if(x[1]=='!' && (obj->find(x[0]-'a'))==(obj->find(x[3]-'a')))
                return false;
        }
        return true;
    }
};