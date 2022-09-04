class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1,l=0,r=1,sum=nums[0];
        while(r<nums.size())
        {
            while((sum&nums[r])!=0)
                sum = sum^nums[l++];
            sum = sum | nums[r];
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};