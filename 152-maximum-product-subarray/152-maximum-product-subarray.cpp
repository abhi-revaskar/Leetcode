class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN,mx =1,mn=1;
        for(auto x:nums)
        {
            if(x>0)
            {
                mx = max(x,mx*x);
                mn = min(x,mn*x);
                ans = max(mx,ans);
            }
            else if(x<0)
            {
                int t = mx;
                mx = max(mn*x,x);
                mn = min(t*x,x);
                ans = max(ans,mx);
            }
            else
            {
                mx = mn = 1;
                ans = max(ans,0);
            }
        }
        return ans;
    }
};