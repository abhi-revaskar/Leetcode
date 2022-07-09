class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        priority_queue<pair<int,int>> q;
        dp[nums.size()-1]=nums.back();
        q.push({nums.back(),nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--)
        {
            int idx = q.top().second;
            int val = q.top().first;
            if(idx-i<=k)
            {
                dp[i]=val+nums[i];
                q.push({dp[i],i});
            }
            else
            {
                while((q.top().second)-i>k)
                    q.pop();
                dp[i]=q.top().first+nums[i];
                q.push({dp[i],i});
            }
            // cout<<dp[i]<<" "<<q.top().first<<endl;
        }
        return dp[0];
    }
};