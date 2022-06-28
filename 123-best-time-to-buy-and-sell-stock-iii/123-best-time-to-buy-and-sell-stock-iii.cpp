class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currprof = 0,mini=prices[0];
        vector<int> left(prices.size()),right(prices.size());
        left[0]=0,right[prices.size()-1]=0;
        for(int i =1;i<prices.size();i++)
        {
            if(prices[i]>=mini)
                currprof=prices[i]-mini;
            else
            {
                mini=prices[i];
                currprof = 0;
            }
            left [i]=currprof;
        }
        currprof=-1;
        mini = prices.back();
        for(int i =prices.size()-2;i>=0;i--)
        {
            if(prices[i]<=mini)
                currprof=mini-prices[i];
            else
            {
                mini=prices[i];
                currprof = 0;
            }
            right [i]=max(right[i+1],currprof);
        }
        // for(auto x:left)
        //     cout<<x<<" ";
        // for(auto x:right)
        //     cout<<x<<" ";
        int ans=0;
        for(int i =0;i<prices.size()-1;i++)
        {
            ans = max(ans,right[i]+left[i]);
        }
        return ans;
    }
};