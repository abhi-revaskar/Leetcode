class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int a=1,b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a)
                a++;
            if(i>0 && nums[i]==nums[i-1])
                b = nums[i];
        }
        return {b,a};
    }
};