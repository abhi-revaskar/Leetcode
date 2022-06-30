class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int mask = 2;
        int cnt = 4;
        ans[0]=0;
        if(n==0)
            return ans;
        ans[1]=1;
        if(n==1)
            return ans;
        for(int i=2;i<=n;i++)
        {
            if(i==cnt)
            {
                cnt*=2;
                mask<<=1;
            }
            ans[i]=ans[i&(~mask)]+1;
        }
        return ans;
    }
};