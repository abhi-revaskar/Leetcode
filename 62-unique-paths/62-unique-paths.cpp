class Solution {
public:
    int uniquePaths(int m, int n) {
        long long num = n,ans=1;
        for(int i=1;i<=m-1;i++)
        {
            ans*=(num);
            ans/=i;
            num++;
        }
        return ans;
    }
};