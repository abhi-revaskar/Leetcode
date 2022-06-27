class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int a[500002];
        memset(a,0,sizeof(a));
        for(auto x:nums)
        {
            if(x>0 && x<=500000)
                a[x]=1;
        }
        for(int i=1;i<500002;i++)
            if(a[i]==0)
                return i;
        return 1;
    }
};