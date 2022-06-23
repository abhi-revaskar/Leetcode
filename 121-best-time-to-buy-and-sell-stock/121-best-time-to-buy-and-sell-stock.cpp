class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;
        int max_profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            min_price=min(min_price,prices[i]);
            max_profit=max(prices[i]-min_price,max_profit);
        }
        return max_profit;
    }
};