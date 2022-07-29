class DSU{
    public:
    unordered_map<string,string> par;
    unordered_map<string,int> rank;
    DSU(unordered_map<string,string> name)
    {
        for(auto x:name)
        {
            par[x.first] = x.first;
            rank[x.first] = 1;
        }
    }
    void add(string email1,string email2)
    {
        string par1 = find(email1);
        string par2 = find(email2);
        if(par1==par2)
            return;
        if(rank[par1]>=rank[par2])
        {
            par[par2] = par1;
            rank[par1]+=rank[par2];
        }
        else
        {
            par[par1] = par2;
            rank[par2]+=rank[par1];
        }
    }
    string find(string email)
    {
        if(par[email]==email)
            return email;
        return par[email] = find(par[email]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> name;
        unordered_map<string,set<string>> component;
        vector<vector<string>> ans;
        for(int j=0;j<accounts.size();j++)
        {
            auto x = accounts[j];
            for(int i=1;i<x.size();i++)
                name[x[i]] = x[0]+to_string(j);
        }
        DSU *obj = new DSU(name);
        for(auto x:accounts)
        {
            for(int i=2;i<x.size();i++)
            {
                obj->add(x[i],x[i-1]);
            }
        }
        for(auto x:name)
        {
            obj->find(x.first);
            // cout<<x.first<<" "<<obj->find(x.first)<<" "<<name[x.first]<<endl;
        }
        for(auto x:obj->par)
        {
            component[name[x.second]].insert(x.first);
        }
        for(auto x:component)
        {
            vector<string> acc;
            string id = "";
            for(int i=0;i<(x.first.length());i++)
            {
                if(x.first[i]>='0' && x.first[i]<='9')
                    break;
                id+=x.first[i];
            }
            acc.push_back(id);
            for(auto y:x.second)
                acc.push_back(y);
            ans.push_back(acc);
        }
        return ans;
    }
};