class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int k,int m,vector<int> &nums,vector<int> &mul)
    {
        int j = nums.size()-1-k+i;
        if(k==m)
        {
            return 0;
        }
        if(dp[i][k]!=INT_MIN)
            return dp[i][k];
        return dp[i][k] = max(solve(i+1,k+1,m,nums,mul)+mul[k]*nums[i],solve(i,k+1,m,nums,mul)+mul[k]*nums[j]);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(),m=multipliers.size();
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
                dp[i][j] = INT_MIN;
        }
        return solve(0,0,m,nums,multipliers);
    }
};