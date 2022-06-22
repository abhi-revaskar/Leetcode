class trie
{
    public:
    trie* node[2];
    int n;
    trie()
    {
        node[0]=node[1]=NULL;
    }
    void put(int i)
    {
        node[i] = new trie();
    }
};
class Trie{
    trie *root;
    public:
    Trie()
    {
        root = new trie();
    }
    void add(int s)
    {
        trie *curr = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (s>>i)&1;
            if(curr -> node[bit]==NULL)
                curr->put(bit);
            curr = curr ->node[bit];
        }
        curr ->n = s;
    }
    int get(int a)
    {
        trie *curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = !((a>>i)&1);
            if(curr -> node[bit]!=NULL)
                curr = curr->node[bit];
            else
                curr = curr ->node [!bit];
        }
        return curr -> n;
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> qq(q);
        for(int i=0;i<q.size();i++)
        {
            qq[i].push_back(i);
        }
        sort(qq.begin(),qq.end(),comp);
        Trie *node=new Trie();
        vector<int> ans(q.size());
        int i=0;
        for(auto x:qq)
        {
            int ub = upper_bound(nums.begin(),nums.end(),x[1]) - nums.begin();
            if(ub==0)
            {
                ans[x[2]] = (-1);
                continue;
            }
            while(i<ub)
            {
                node->add(nums[i]);
                i++;
            }
            ans[x[2]]=(x[0]^node->get(x[0]));
        }
        return ans;
    }
};