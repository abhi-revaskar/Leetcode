class Solution {
    vector<int> bit;
    void update(int i)
    {
        i++;
        while(i<bit.size())
        {
            bit[i]++;
            i+=i&-i;
        }
    }
    int sum(int i)
    {
        i++;
        int ans =0;
        while(i)
        {
            ans+=bit[i];
            i-=i&-i;
        }
        return ans;
    }
    int query(int l,int r)
    {
        return sum(r) - sum(l-1);
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(),ans=0;
        bit.assign(n+2,0);
        vector<long long> psum(n),sortsum(n);
        psum[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            psum[i] = psum[i-1]+nums[i];
        }
        sortsum = psum;
        sortsum.push_back(0);
        sort(sortsum.begin(),sortsum.end());
        int idx = lower_bound(sortsum.begin(),sortsum.end(),0)-sortsum.begin();
        update(idx);
        for(auto x:psum)
        {
            // if(x>=lower && x<=upper)
            //     ans++;
            int l = lower_bound(sortsum.begin(),sortsum.end(),x-upper)-sortsum.begin();
            int r = upper_bound(sortsum.begin(),sortsum.end(),x-lower)-sortsum.begin();
            r--;
            if(l<=r)
            ans+=query(l,r);
            // cout<<l<<" "<<r<<" ";
            // cout<<ans<<endl;
            int idx = lower_bound(sortsum.begin(),sortsum.end(),x)-sortsum.begin();
            update(idx);
        }
        return ans;
    }
};