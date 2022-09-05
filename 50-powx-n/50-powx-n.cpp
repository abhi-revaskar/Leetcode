class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0)
            return 1/myPow(x,-n);
        if(n==0)
            return 1;
        if(n==1)
            return x;
        double half = myPow(x,n/2);
        if(n&1)
            return half*half*x;
        return half*half;
    }
};