class Trie{
    public:
    unordered_map<char,Trie*> child;
    int sum; //sum of string values having this prefix   
    Trie()
    {
        sum = 0;
    }
};
class MapSum {
public:
    Trie *root;
    unordered_map<string,int> mp;
    MapSum() {
        root = new Trie;
    }
    
    void insert(string key, int val) {
        int diff = val - mp[key];
        Trie *curr = root;
        for(auto x:key)
        {
            if(curr->child.count(x)==0)
                curr->child[x] = new Trie();
            curr = curr->child[x];
            curr->sum+=diff;
        }
        mp[key] = val;
    }
    
    int sum(string prefix) {
        Trie *curr = root;
        for(auto x:prefix)
        {
            if(curr->child.count(x)==0)
                return 0;
            curr = curr->child[x];
        }
        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */