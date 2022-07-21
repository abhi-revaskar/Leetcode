class Solution {
public:
    int numTrees(int n) {
        double num = 2*n,ans = 1;
        for(double i=1;i<=n;i++)
        {
            ans*=(num/i);
            num--;
            // cout<<ans<<" ";
        }
        return ans/(n+1.0);
    }
};