class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> pre(nums.size()),suff(nums.size());
        pre[0]=nums[0];suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]*nums[i];
            suff[n-i-1] = nums[n-i-1]*suff[n-i];
        }
        for(int i=0;i<n;i++)
        {
            int p = i==0?1:pre[i-1];
            int s = i==n-1?1:suff[i+1];
            ans.push_back(p*s);
        }
        return ans;
    }
};