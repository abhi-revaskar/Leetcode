class Solution {
public:
    bool find(int i,vector<int> &nums,vector<int> &part,int &t)
    {
        if(i==nums.size())
        {
            return true;
        }
        
        int f = 0;
        for(int j=0;j<part.size();j++)
        {
            if(part[j]+nums[i]<=t)
            {
                part[j]+=nums[i];
                if(find(i+1,nums,part,t))
                    return true;
                part[j]-=nums[i];
                if(part[j]==0)
                    return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> part(k,0);
        int sum=0;
        for(auto x:nums)
            sum+=x;
        if(sum%k!=0)
            return false;
        // cout<<sum/k;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int t = sum/k;
        return find(0,nums,part,t);
    }
};