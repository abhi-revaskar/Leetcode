class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        long long multi = m+n-2;
        for(int i=1;i<min(m,n);i++)
        {
            ans = ans*multi/(1LL*i);
            multi--;
        }
        return ans;
    }
};