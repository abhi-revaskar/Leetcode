class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int two=cost[n-1];
        int one=cost[n-2];
        for(int i=n-3;i>=0;i--)
        {
            int curr =min(one,two)+cost[i];
            two=one;
            one=curr;
        }
        return min(one,two);
    }
};