class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int t = -nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                    j++;
                else if(k!=nums.size()-1 && nums[k]==nums[k+1])
                    k--;
                else if(nums[j]+nums[k]==t)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if(nums[j]+nums[k]>t)
                    k--;
                else 
                    j++;                
            }
        }
        return ans;
    }
};