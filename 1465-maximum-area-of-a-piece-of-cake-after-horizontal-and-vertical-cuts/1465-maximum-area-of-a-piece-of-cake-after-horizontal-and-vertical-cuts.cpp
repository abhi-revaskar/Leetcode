class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int maxw = vc[0];
        int maxh = hc[0];
        for(int i=1;i<hc.size();i++)
            maxh = max(maxh,hc[i]-hc[i-1]);
        for(int i = 1;i<vc.size();i++)
            maxw = max(maxw,vc[i]-vc[i-1]);

        maxh = max(maxh,h-hc.back());
        maxw = max(maxw,w-vc.back());
        // cout<<maxh<<" "<<maxw;
        return (maxh*1LL*maxw)%1000000007;
    }
};