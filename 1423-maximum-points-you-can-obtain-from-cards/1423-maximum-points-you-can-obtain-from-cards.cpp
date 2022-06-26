class Solution {
public:
    int maxScore(vector<int>& cp,int k) {
        int ans=INT_MIN;
        int n = cp.size();
        int sum = 0;
        for(auto x:cp)
            sum+=x;
        int i=0,j=0,temp=0;
        while(j<n)
        {
            if(j<n-k)
            {
                temp+=cp[j];
                j++;
            }
            else
            {
                ans = max(ans,sum-temp);
                temp = temp-cp[i]+cp[j];
                i++;j++;
            }
        }
        ans = max(ans,sum-temp);
        return ans;
    }
};