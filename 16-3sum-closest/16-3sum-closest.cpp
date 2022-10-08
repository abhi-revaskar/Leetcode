class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans,diff = INT_MAX;
        sort(begin(nums),end(nums));
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            int t = target-nums[i],j=i+1,k=n-1;
            while(j<k)
            {
                int sum = nums[j]+nums[k];
                if(abs(sum-t)<diff)
                {
                    ans = nums[i]+sum;
                    diff = abs(sum-t);
                }
                if(sum>t)
                    k--;
                else
                    j++;                
            }
        }
        return ans;
    }
};