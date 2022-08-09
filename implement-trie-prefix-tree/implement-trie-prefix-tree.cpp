class trie{
public:
    unordered_map<char,trie*> node;
    int f;
    trie()
    {
        f=0;
    }
};

class Trie {
public:
    trie* root;
    Trie() {
       root = new trie();
    }
    
    void insert(string w) {
        trie *curr = root;
        for(int i=0;i<w.length();i++)
        {
            if(curr->node.find(w[i])==curr->node.end())
                curr->node[w[i]]= new trie();
            curr=curr->node[w[i]];
        }
        curr->f=1;
    }
    
    bool search(string w) {
        trie *curr = root;
        for(int i=0;i<w.length();i++)
        {
            if(curr->node.find(w[i])==curr->node.end())
                return false;
            curr=curr->node[w[i]];
        }
        if(curr->f)
            return true;
        return false;
    }
    
    bool startsWith(string w) {
        trie *curr = root;
        for(int i=0;i<w.length();i++)
        {
            if(curr->node.find(w[i])==curr->node.end())
                return false;
            curr=curr->node[w[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */