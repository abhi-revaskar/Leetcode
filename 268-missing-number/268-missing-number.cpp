class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0,n = nums.size(),tot=0;
        for(int i=1;i<=n;i++)
            tot^=i;
        for(auto x:nums)
            sum^=x;
        return sum^tot;
    }
};