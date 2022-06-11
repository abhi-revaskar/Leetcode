class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans=-1;
        int n = nums.size();
        vector<int> sum(n);
        sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        for(int i = 0; i<n;i++)
        {
            mp[sum[i]]=i;
        }
        int t = sum[n-1]-x;
        for(int i=0;i<n;i++)
        {
            if(sum[i]==t)
                ans=max(ans,i+1);
            if(mp.find(sum[i]-t)!=mp.end())
                ans=max(ans,i-mp[sum[i]-t]);
        }
        return ans==-1?ans:n-ans;
    }
};