class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size(),ans = 0,lmax,rmax;
        vector<int> prev(n,-1),next(n,-1);
        lmax= height[0],rmax=height[n-1];
        for(int i=1;i<n;i++)
        {
            prev[i] = lmax;
            lmax = max(lmax,height[i]);
            next[n-1-i] = rmax;
            rmax = max(rmax,height[n-1-i]);
        }
        for(int i=0;i<n;i++)
        {
            // cout<<prev[i]<<" "<<next[i]<<endl;
            if(prev[i]>height[i] && next[i]>height[i])
                ans+=(min(prev[i],next[i]))-height[i];
        }
        return ans;
    }
};