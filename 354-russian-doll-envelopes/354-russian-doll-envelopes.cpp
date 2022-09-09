class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
        return a[0]<b[0];
        return a[1]>b[1];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        // for(auto &x:env)
        //     swap(x[0],x[1]);
        sort(env.begin(),env.end(),comp);
        vector<int> lis;
        lis.push_back(env[0][1]);
        int ans = 1;
        for(int i=1;i<env.size();i++)
        {
            int idx = lower_bound(lis.begin(),lis.end(),env[i][1])-lis.begin();
            if(idx==lis.size())
                lis.push_back(env[i][1]);
            else
                lis[idx] = env[i][1];
            ans = max(ans,int(lis.size()));
            // cout<<ans<<endl;
        }
        return ans;
    }
};