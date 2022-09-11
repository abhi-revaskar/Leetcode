class Solution {
    int mod = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> val;
        long long ans = 0,sum=0;
        for(int i=0;i<n;i++)
        {
            val.push_back({efficiency[i],speed[i]});
        }
        sort(val.begin(),val.end());
        reverse(val.begin(),val.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:val)
        {
            sum+=x.second;
            pq.push(x.second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();                
            }
            ans = max(ans,(sum*x.first));
            // cout<<x.first<<" "<<x.second<<" "<<sum<<" "<<ans<<endl;
        }
        return ans%mod;
    }
};