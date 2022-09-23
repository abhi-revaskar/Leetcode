class Solution {
    int mod = 1e9+7;
public:
    int bits(int n)
    {
        return int(log(n)/log(2))+1;
    }
    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans = (ans<<bits(i))%mod;
            ans = (ans+i)%mod;
        }
        return ans;
    }
};