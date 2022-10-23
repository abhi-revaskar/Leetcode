class Solution {
public:
    long long f(long long m,vector<int>& nums, vector<int>& cost)
    {
        long long ans = 0;
        for(int i=0;i<cost.size();i++)
            ans+=(abs(m-nums[i])*cost[i]);
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = *min_element(begin(nums),end(nums)),r = *max_element(begin(nums),end(nums));
        while(l<r)
        {
            long long m1 = (l+r)/2;
            long long m2 = m1+1;
            // cout<<l<<" "<<r<<endl;
            if(f(m1,nums,cost)<=f(m2,nums,cost))
                r = m2-1;
            else
                l = m1+1;
        }
        long long ans = 0;
        for(int i=0;i<cost.size();i++)
            ans+=abs(l-nums[i])*cost[i];
        return ans;
    }
};