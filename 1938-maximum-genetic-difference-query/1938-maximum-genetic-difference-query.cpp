class trienode{
    public:
    vector<trienode*> child;
    int cnt;
    trienode()
    {
        child.assign(2,NULL);
        cnt=0;
    }
};
class trie{
    public:
    trienode* root;
    trie()
    {
        root = new trienode;
    }
    void update(int n,int x)
    {
        trienode *t =root;
        // cout<<n<<endl;
        for(int i=17;i>=0;i--)
        {
            bool bit = (n&(1<<i));
            if(t->child[bit]==NULL)
            {
                t->child[bit] = new trienode;
            }
            // cout<<bit<<" ";
            t = t->child[bit];
            t->cnt+=x;                
        }
        // cout<<endl;
    }
    int find(int n)
    {
        int ans = 0;
        trienode *t = root;
        for(int i=17;i>=0;i--)
        {
            bool bit = (n&(1<<i));
            if(t->child[bit^1]!=NULL && t->child[bit^1]->cnt)
            {
                ans = ans|(1<<i);
                t = t->child[bit^1];
            }
            else if(t->child[bit]!=NULL && t->child[bit]->cnt)
                t = t->child[bit];
            else
                break;
        }
        return ans;
    }
};
class Solution {
    unordered_map<int,vector<pair<int,int>>> mp;
    vector<int> ans;
    void dfs(int v,int par,vector<vector<int>> &adj,trie* &obj)
    {
        // cout<<v<<": ";
        obj->update(v,1);
        for(auto &x:mp[v])
        {
            ans[x.second] = obj->find(x.first);
            // cout<<ans[x.second]<<" ";
        }
        // cout<<endl;
        for(auto &x:adj[v])
        {
            if(x!=par)
            {
                dfs(x,v,adj,obj);
            }
        }
        obj->update(v,-1);
    }
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        ans.resize(queries.size());
        int root;
        trie* obj = new trie;
        vector<vector<int>> adj(parents.size());
        int n = parents.size();
        for(int i=0;i<n;i++)
        {
            if(parents[i]==-1)
                root = i;
            else
                adj[parents[i]].push_back(i);
        }
        for(int i=0;i<queries.size();i++)
        {
            auto &x = queries[i];
            mp[x[0]].push_back({x[1],i});
        }
        dfs(root,-1,adj,obj);
        return ans;
    }
};