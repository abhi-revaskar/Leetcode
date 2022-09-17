class trienode{
    public:
    unordered_map<char,trienode*> child;
    int idx;
    trienode()
    {
        idx=-1;
    }
};
class trie{
    trienode *root;
    public:
    trie()
    {
        root = new trienode();
    }
    void insert(string s,int idx)
    {
        trienode* t = root;
        for(int i=0;i<s.length();i++)
        {
            if(t->child[s[i]]==NULL)
                t->child[s[i]] = new trienode();
            t = t->child[s[i]];
        }
        t->idx=idx;
    }
    unordered_set<int> find(string s,int idx)
    {
        unordered_set<int> ans;
        trienode* t = root;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(t->child[c]==NULL)
                return ans;
            t= t->child[c];
            if(t->idx!=-1 && t->idx !=idx && check(s,i+1))
            {
                // cout<<idx<<" "<<c<<endl;
                // cout<<t->idx;
                ans.insert(t->idx);
                // cout<<ans.size()<<endl;
            }
            // cout<<idx<<" "<<ans.size()<<endl;
        }
        // cout<<idx<<" "<<ans.size()<<endl;
        if(t->idx!=idx && t->idx!=-1)
        {
            ans.insert(t->idx);
        }
        dfs(t,idx,"",ans);
        return ans;
    }
    void dfs(trienode* t,int i,string s,unordered_set<int> &ans)
    {
        if(t==NULL)
            return;
        if(t->idx!=-1 && t->idx!=i && check(s))
            ans.insert(t->idx);
        for(auto x:t->child)
        {
            dfs(x.second,i,s+x.first,ans);
        }
    }
    bool check(string &s)
    {
        if(s=="")
            return false;
        int n = s.length();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
    bool check(string &s,int i)
    {
        int n = s.length()-1;
        while(i<n)
        {
            if(s[i]!=s[n])
                return false;
            i++;n--;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        trie *root = new trie();
        vector<vector<int>> ans;
        int emptyidx=-1;
        for(int i=0;i<words.size();i++)
        {
            string x = words[i];
            if(x=="")
            {
                emptyidx=i;
                continue;
            }
            reverse(begin(x),end(x));
            root->insert(x,i);
        }
        for(int i=0;i<words.size();i++)
        {
            if(i==emptyidx)
                continue;
            if(emptyidx!=-1 && root->check(words[i]))
            {
                ans.push_back({i,emptyidx});
                ans.push_back({emptyidx,i});
            }
            unordered_set<int> idx = root->find(words[i],i);
            // cout<<i<<" "<<idx.size()<<endl;
            for(auto x:idx)
            {
                // cout<<i<<" "<<x<<endl;
                ans.push_back({i,x});
            }
        }
        return ans;
    }
};
