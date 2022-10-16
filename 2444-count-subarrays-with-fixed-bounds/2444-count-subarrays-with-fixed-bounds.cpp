class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0,minidx=0,maxidx=0,minf=0,mxf=0,start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxK || nums[i]<minK)
            {
                minf=0;
                mxf=0;
                start= i+1;
            }
            if(nums[i]==minK)
            {
                minf=1;
                minidx=i;
            }
            if(nums[i]==maxK)
            {
                mxf=1;
                maxidx=i;
            }
            if(mxf && minf)
            {
                ans+=(min(maxidx,minidx)-start+1);
            }
        }
        return ans;
    }
};