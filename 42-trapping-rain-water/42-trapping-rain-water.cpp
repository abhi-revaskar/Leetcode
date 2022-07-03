class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size(),ans = 0;
        int leftmax=h[0],rightmax=h[n-1];
        int l=0,r=n-1;
        while(l<=r)
        {
            if(h[l]<=h[r])
            {
                if(h[l]>=leftmax)
                    leftmax = h[l];
                else
                    ans+=min(leftmax,h[r])-h[l];
                l++;                
            }
            else
            {
                if(h[r]>=rightmax)
                    rightmax = h[r];
                else
                    ans+=min(rightmax,h[l]) - h[r];
                r--;
            }
        }
        return ans;
    }
};