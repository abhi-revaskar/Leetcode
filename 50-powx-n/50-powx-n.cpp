class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        long long t = abs(n);
        double res = 1;
        double a = x;
        while(t)
        {
            if(t&1)
                res*=a;
            a = a*a;
            t>>=1;
        }
        if(n<0)
            return 1/res;
        return res;
    }
};