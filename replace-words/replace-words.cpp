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
    TrieNode* root;
    Trie()
    {
        root = new TrieNode;
    }
    void insert(string word)
    {
        TrieNode* curr = root;
        for(auto c: word)
        {
            if(curr->child.count(c)==0)
                curr->child[c] = new TrieNode;
            curr = curr->child[c];
        }
        curr -> valid = 1;
    }
    string findroot(string word)
    {
        TrieNode* curr = root;
        string ans = "";
        for(auto c:word)
        {
            if(curr->child.count(c)==0)
                return word;
            curr = curr->child[c];
            if(curr->valid)
                return ans+c;
            ans+=c;
        }
        return ans;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *root = new Trie();
        for(auto word:dictionary)
            root->insert(word);
        string ans = "";
        string word = "";
        for(auto c:sentence)
        {
            if(c!=' ')
                word+=c;
            else
            {
                ans +=root->findroot(word)+' ';
                word = "";
            }
        }
        ans +=root->findroot(word);
        return ans;
    }
};