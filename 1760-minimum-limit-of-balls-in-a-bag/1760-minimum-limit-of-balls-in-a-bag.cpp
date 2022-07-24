class Solution {
public:
    bool possible(int &mid,vector<int> &nums,int ops)
    {
        int totalops = 0;
        for(int i=0;i<nums.size();i++)
        {
            totalops+=((nums[i]-1)/mid);
        }
        return totalops<=ops;
    }
    int minimumSize(vector<int>& nums, int ops) {
        int low = 1,high = 0;
        for(auto &x:nums)
            high = max(high,x);
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(mid,nums,ops))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};