class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest/minutesToDie;
        int l = 0,h=1000;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(pow(tests+1,mid)>=buckets)
                h = mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};