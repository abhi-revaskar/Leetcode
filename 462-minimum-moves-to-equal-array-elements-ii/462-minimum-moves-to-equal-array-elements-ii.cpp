class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        int mid = nums[nums.size()/2] ;
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            ans+=abs(nums[l]-mid)+abs(nums[r]-mid);
            l++;r--;
        }
        return ans;
    }
};