class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(),ans=nums[0];
        vector<int> sum(n);
        sum[0]=nums[0];
        for(int i = 1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
        }
        unordered_map<int,int> mp;
        int l=0,r=1;
        mp[nums[l]]=l;
        while(r<n)
        {
            if(mp.find(nums[r])==mp.end())
            {
                ans=max(ans,sum[r]-(l==0?0:sum[l-1]));
                mp[nums[r]]=r;
                r++;
            }
            else
            {
                if(mp[nums[r]]<l)
                {
                    ans=max(ans,sum[r]-(l==0?0:sum[l-1]));
                    mp[nums[r]]=r;
                    r++;
                }
                else
                {
                    l=mp[nums[r]]+1;
                }
            }
        }
        return ans;
    }
};