class Solution {
public:
    double myPow(double x, long long n) {
        if(n==1)
            return x;
        if(n==0)
            return 1;
        if(n<0)
            return double(1)/(myPow(x,-n));
        double half = myPow(x,n/2);
        if(n&1)
            return half*half*x;
        return half*half;
    }
};