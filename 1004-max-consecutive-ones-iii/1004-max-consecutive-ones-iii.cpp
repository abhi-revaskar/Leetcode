class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int start = 0,end = 0;
        while(end<nums.size())
        {
            if(nums[end]==1)
                end++;
            else
            {
                if(k)
                {
                    k--;
                    end++;
                }
                else
                {
                    ans = max(ans,end-start);
                    if(nums[start]==0)
                        k++;
                    start++;
                }
            }
        }
        ans = max(ans,end-start);
        return ans;
    }
};