class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> s;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(i>0 && sum%k==0)
                return true;
            if(s.count(sum%k) && s[sum%k]<i-1)
                return true;
            if(s.count(sum%k)==0)
                s[sum%k]=i;
                
        }
        return false;
    }
};