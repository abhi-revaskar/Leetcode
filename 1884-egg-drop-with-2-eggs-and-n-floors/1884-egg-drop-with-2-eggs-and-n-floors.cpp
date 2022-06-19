class Solution {
public:
    int twoEggDrop(int n) {
        int ans = 0;
        int l=1,r=45,m;
        while(l<=r)
        {
            // cout<<l<<" "<<r<<endl;
            m = (l+r)/2;
            int sum = m*(m+1)/2;
            if(n==sum)
                return m;
            if(n>sum)
                l=m+1;
            else 
                r=m-1;
        }
        return l;
    }
};