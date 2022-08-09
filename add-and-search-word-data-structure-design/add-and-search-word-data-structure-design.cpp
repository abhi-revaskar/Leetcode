class TrieNode{
    public:
    unordered_map<char,TrieNode*> child;
    int valid;
    TrieNode()
    {
        valid = 0;
    }
};
class Trie{
    public:
    void insert(const string &word,TrieNode* &root)
    {
        TrieNode* curr = root;
        for(auto &c: word)
        {
            if(curr->child.count(c)==0)
                curr->child[c] = new TrieNode;
            curr = curr->child[c];
        }
        curr -> valid = 1;
    }
    bool search(const string &word,TrieNode* &root)
    {
        TrieNode* curr = root;
        int ans = 0;
        for(int i=0;i<word.size();i++)
        {
            char c = word[i];
            if(c!='.' && curr->child.count(c)==0)
                return false;
            if(c=='.')
            {
                for(auto &x:curr->child)
                {
                    string suffix = word.substr(i+1);
                    ans = ans or search(suffix,x.second);
                }
                return ans;
            }
            curr = curr->child[c];
        }
        return curr->valid;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    Trie* obj;
    WordDictionary() {
        root = new TrieNode();
        obj = new Trie();
    }
    
    void addWord(string word) {
        obj->insert(word,root);
    }
    
    bool search(string word) {
        return obj->search(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */