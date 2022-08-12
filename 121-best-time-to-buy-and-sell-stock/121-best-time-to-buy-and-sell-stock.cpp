class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int ans = 0,min=pr[0];
        for(int i=1;i<pr.size();i++)
        {
            if(pr[i]<min)
                min=pr[i];
            else
                ans = max(ans,pr[i]-min);
        }
        return ans;
    }
};