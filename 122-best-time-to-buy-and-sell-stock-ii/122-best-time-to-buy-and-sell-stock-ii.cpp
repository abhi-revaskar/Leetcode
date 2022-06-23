class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
                min = prices[i];
            else 
            {
                ans += prices[i]-min;
                min = prices[i];
            }
        }
        return ans;
    }
};