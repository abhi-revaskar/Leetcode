class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        vector<int> ans;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        ans.push_back(low);
        low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]<=target)
                low = mid+1;
            else 
                high = mid-1;
        }
        ans.push_back(high);
        if(ans[0]>ans[1])
            return {-1,-1};
        return ans;
    }
};