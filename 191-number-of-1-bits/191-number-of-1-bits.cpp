class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return __builtin_popcount(n);
        int ans = 0;
        while(n)
        {
            ans++;
            n = n&(n-1);
        }
        return ans;
    }
};