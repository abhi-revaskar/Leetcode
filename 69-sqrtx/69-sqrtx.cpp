class Solution {
public:
    int mySqrt(int x) {
        long long l=0,h=1<<16;
        while(l<=h)
        {
            long long mid = (l+h)/2;
            if(mid*mid==x)
                return mid;
            if(mid*mid>x)
                h=mid-1;
            else
                l=mid+1;
        }
        return h;
    }
};