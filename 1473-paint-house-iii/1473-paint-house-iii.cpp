class Solution {
public:
    const int MAX = 1000001;
    int dp[101][21][101];
    int solve(int houseno,int color,int nbr,vector<vector<int>> &cost,vector<int> &houses,int target)
    {
        if(houseno==houses.size())
            return ((target==nbr)?0:MAX);
        
        if(nbr > target)
            return MAX;
        
        if(dp[houseno][color][nbr]!=-1)
            return dp[houseno][color][nbr];
        int ans = MAX;
        if(houses[houseno])
        {
            int newnbr = nbr + (color!=houses[houseno]);
            ans = solve(houseno+1,houses[houseno],newnbr,cost,houses,target);
        }
        else
        {
            for(int i=1;i<=cost[0].size();i++)
            {
                int newnbr = nbr+(color!=i);
                int currcost = solve(houseno+1,i,newnbr,cost,houses,target)+cost[houseno][i-1];
                ans = min(ans,currcost);
            }
        }
        return dp[houseno][color][nbr] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans =solve(0,0,0,cost,houses,target);
        return (ans==MAX)?-1:ans;
    }
};