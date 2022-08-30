class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2)
            return min(cost[0],cost[1]);
        // int dp[n];
        int next2 = cost[n-1],next1 = cost[n-2];
        for(int i=n-3;i>=0;i--)
        {
            int curr = min(next1,next2)+cost[i];
            next2 = next1;
            next1 = curr;
        }
        return min(next1,next2);
    }
};