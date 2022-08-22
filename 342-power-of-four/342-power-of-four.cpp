class Solution {
public:
    bool isPowerOfFour(long long n) {
        if (n>0 && (n&(n-1))==0 && n&(0x55555555))
            return true;
        return false;
    }
};