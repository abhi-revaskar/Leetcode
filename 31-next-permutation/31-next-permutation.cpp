class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot=n-1;
        while(pivot>0 && nums[pivot]<=nums[pivot-1])
        {
            pivot--;
        }
        if(pivot==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int swapidx=pivot;
        while(swapidx<n && nums[swapidx]>nums[pivot-1])
            swapidx++;
        swapidx--;
        swap(nums[pivot-1],nums[swapidx]);
        reverse(nums.begin()+pivot,nums.end());
        
    }
};