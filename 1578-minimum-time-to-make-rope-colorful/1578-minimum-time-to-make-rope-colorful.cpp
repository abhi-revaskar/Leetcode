class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int ans = 0,sum=time[0],mx=time[0];
        for(int i=1;i<colors.length();i++)
        {
            if(colors[i]==colors[i-1])
            {
                sum+=time[i];
                mx = max(mx,time[i]);
            }
            else
            {
                ans+=(sum-mx);
                sum = time[i];
                mx = time[i];
            }
        }
        ans+=(sum-mx);
        return ans;
    }
};