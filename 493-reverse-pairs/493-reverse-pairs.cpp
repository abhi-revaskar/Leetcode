class Solution {
    vector<int> bit;
    
    void update(int i)
    {
        i++;
        while(i<bit.size())
        {
            bit[i]++;
            i = i+(i&-i);
        }
    }
    int sum(int i)
    {
        i++;
        int ans = 0;
        while(i)
        {
            ans+=bit[i];
            i -= i&-i;
        }
        return ans;
    }
    int query(int l,int r)
    {
        return sum(r)- sum(l-1);
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> sorted(nums);
        int n = nums.size(),ans = 0;
        sort(sorted.begin(),sorted.end());
        bit.resize(n+1,0);
        for(auto x:nums)
        {
            int idx = upper_bound(sorted.begin(),sorted.end(),2LL*x)-sorted.begin();
            if(idx<n)
            ans+=query(idx,n-1);
            idx = lower_bound(sorted.begin(),sorted.end(),x)-sorted.begin();
            update(idx);
        }
        return ans;
    }
};