class trienode{
    public:
    unordered_map<int,trienode*> child;
};
class trie{
    public:
    trienode *root;
    trie()
    {
        root = new trienode;
    }
    void insert(int n)
    {
        trienode *curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i)&1;
            if(curr->child.count(bit)==0)
                curr->child[bit] = new trienode;
            curr = curr->child[bit];
        }
    }
    int findxor(int n)
    {
        trienode* curr = root;
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = !((n>>i)&1);
            if(curr->child.count(bit)==0)
            {
                ans = (ans<<1)+(!bit);
                curr = curr->child[!bit];
            }
            else
            {
                ans = (ans<<1)+bit;
                curr = curr->child[bit];
            }
        }
        return (ans^n);
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie *root = new trie;
        for(auto x:nums)
            root->insert(x);
        int ans = 0;
        for(auto x:nums)
            ans = max(ans,root->findxor(x));
        return ans;
    }
};