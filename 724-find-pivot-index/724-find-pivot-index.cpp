class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans =-1;
        if(nums.size()==1)
            return 0;
        vector<int> sum;
        int t = 0;
        for(auto x:nums)
        {
            t+=x;
            sum.push_back(t);
        }
        for(int i=0;i<nums.size();i++)
        {
            int l = i==0?0:sum[i-1];
            int r = i==nums.size()-1?0:sum.back()-sum[i];
            if(l==r)
                return i;
        }
        return -1;
    }
};