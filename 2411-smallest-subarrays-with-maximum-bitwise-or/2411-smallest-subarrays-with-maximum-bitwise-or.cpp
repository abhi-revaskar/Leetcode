class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> last(32,-1),ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
            int maxlast = i,x=nums[i];
            for(int j=0;j<32;j++)
            {
                if(x&(1<<j))
                    last[j]=i;
                else
                    maxlast = max(maxlast,last[j]);
            }
            ans[i] = (maxlast-i+1);
        }
        return ans;
    }
};