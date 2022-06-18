class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        int n = coins.size();
        vector<long long> prev(am+1,0),curr(am+1);
        for(int i = 1;i<=am;i++)
        {
            prev[i]=INT_MAX;
        }
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
            for(int j=1;j<=am;j++)
            {
                if(coins[i-1]>j)
                    curr[j]=prev[j];
                else
                {
                    curr[j] = min(1+prev[j-coins[i-1]],
                                  min(1+curr[j-coins[i-1]],prev[j]));
                }
                    
            }
            prev=curr;
        }
        return prev[am]==INT_MAX?-1:prev[am];
    }
};