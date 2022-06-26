class Solution {
public:
    int dp[10001];
   bool solve(vector<int>& nums,int i=0) {
        
        if(dp[i]!=-1)
            return dp[i];
        if(i==nums.size()-1)
            return dp[i]=true;
        
        if(nums[i]==0)
            return dp[i]=false;
        
        for(int j=1;j<=nums[i];j++)
            if(solve(nums,i+j))
                return dp[i]=true;
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};