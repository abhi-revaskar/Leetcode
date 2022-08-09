class Trie{
    public:
    unordered_map<char,Trie*> child;
    unordered_map<string,int> mp;
    
};
class MapSum {
public:
    Trie *root;
    MapSum() {
        root = new Trie;
    }
    
    void insert(string key, int val) {
        Trie *curr = root;
        for(auto x:key)
        {
            if(curr->child.count(x)==0)
                curr->child[x] = new Trie();
            curr = curr->child[x];
            curr->mp[key] =val;
        }
    }
    
    int sum(string prefix) {
        int ans = 0;
        Trie *curr = root;
        for(auto x:prefix)
        {
            if(curr->child.count(x)==0)
                return 0;
            curr = curr->child[x];
        }
        for(auto x:curr->mp)
            ans+=x.second;
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */