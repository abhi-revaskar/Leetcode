class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=1,n=nums.size();
        if(n==1)
            return true;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<jump)
                jump++;
            else
                jump=1;
        }
        return nums[0]>=jump;
    }
};