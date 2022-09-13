class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        unordered_map<int,int> last;
        for(int i=0;i<m;i++)
        {
            last[i+1] = i;
        }
        vector<int> ans(n);
        ans[0] = queries[0]-1;
        last[queries[0]] = 0;
        for(int i=1;i<n;i++)
        {
            unordered_set<int> s,t;
            for(int j=i-1;j>=0 && queries[j]!=queries[i];j--)
            {
                if(queries[j]>queries[i])
                    s.insert(queries[j]);
                t.insert(queries[j]);
            }
            if(last[queries[i]]!=0)
            ans[i] = last[queries[i]]+s.size();
            else
                ans[i] = last[queries[i]]+t.size();
            last[queries[i]]=0;
        }
        return ans;
    }
};
