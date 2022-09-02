class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0,end = nums[0],n = nums.size(),ans=1;
        if(n==1)
            return 0;
        while(true)
        {
            int newend = end;
            for(int i=start;i<min(n,end+1);i++)
            {
                if(i==nums.size()-1)
                    return ans;
                newend = max(newend,i+nums[i]);
            }
            start = end+1;
            end = newend;
            ans++;
        }
        return ans;
    }
};