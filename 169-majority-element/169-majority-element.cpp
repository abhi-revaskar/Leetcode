class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(cnt==0)
            {
                maj = nums[i];
                cnt=1;
            }
            else if(nums[i]!=maj)
                cnt--;
            else if(nums[i]==maj)
                cnt++;
        }
        return maj;
    }
};