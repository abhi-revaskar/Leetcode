class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long ans = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            long long tar1 = target - nums[i];
            long long sum = INT_MAX;;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(abs(sum-tar1) > abs(nums[j]+nums[k]-tar1))
                    sum = nums[j]+nums[k];
                if(nums[j]+nums[k]>tar1)
                    k--;
                else
                    j++;
            }
            
            if(abs(ans-target)>abs(nums[i]+sum-target))
                ans = nums[i] + sum;
            // cout<<sum<<" "<<ans<<" ";
        }
           return ans;
                          
                         
    }
};