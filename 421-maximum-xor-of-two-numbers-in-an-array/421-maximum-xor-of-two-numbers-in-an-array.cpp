class trie{
    public:
    unordered_map<int,trie*> node;
};
class Trie{
    public:
    trie *root;
    Trie()
    {
        root= new trie;
    }
    void add(int &s)
    {
        trie* curr = root;
        int t = 1<<30;
        for(int i=0;i<31;i++)
        {
            int bit = !(!(s&t));
            // cout<<bit;
            if(curr->node.find(bit)==curr->node.end())
                curr->node[bit] = new trie;
            curr=curr->node[bit];
            t=t>>1;
        }
        // cout<<endl;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *r = new Trie();
        trie *root = r->root;
        for(auto x:nums)
            r->add(x);
        int ans = 0;
        for(auto a:nums)
        {
            trie *curr=root;
            int m = 1<<30,t=1<<30;
            int b=0;
            m=1<<30;
            while(curr->node.size()!=0)
            {
                int bit = (!(a&t));
                if(curr->node.find(bit)!=curr->node.end())
                {
                    // cout<<"1";
                    if(bit==1)
                    b+=m;
                    curr = curr->node[bit];
                }
                else
                {
                    // cout<<"0";
                    if(bit==0)
                    b+=m;
                    curr = curr->node[!bit];
                }
                m=m>>1;
                t=t>>1;
            }
            ans = max(ans,a^b);
        }
        return ans;
    }
};