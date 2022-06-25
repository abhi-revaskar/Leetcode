class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j = i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                long long  t = target*1LL - nums[i]*1LL-nums[j]*1LL;
                int k = j+1,l = n-1;
                
                while(k<l)
                {
                    
                    if(k>j+1 && nums[k]==nums[k-1])
                    {
                        k++;
                        continue;
                    }
                    if(l<n-1 && nums[l]==nums[l+1])
                    {
                        l--;
                        continue;
                    }
                    if(nums[k]*1LL+nums[l]*1LL==t)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                    }
                    else if(nums[k]*1LL+nums[l]*1LL>t)
                        l--;
                    else 
                        k++;
                      
                }
            }
            
        }
        return ans;
    }
};