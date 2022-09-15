class Solution {
    void add(int l,int r,int h,vector<int> &heights,int &maxh)
    {
        int t = 0;
        for(int i=l;i<=r;i++)
            t = max(t,heights[i]);
        for(int i=l;i<=r;i++)
            heights[i] = t+h;
        maxh = max(maxh,t+h);
    }
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> heights,maxi,ans;
        for(auto x:positions)
        {
            heights.push_back(x[0]);
            heights.push_back(x[1]+x[0]);
        }
        sort(begin(heights),end(heights));
        heights.erase(unique(begin(heights),end(heights)),end(heights));
        int n = heights.size(),maxh=0;
        for(int i=0;i<n;i++)
            heights.push_back(heights[i]);
        sort(begin(heights),end(heights));
        n = heights.size();
        maxi.assign(n,0);
        for(auto x:positions)
        {
            int l = upper_bound(heights.begin(),end(heights),x[0])-begin(heights);
            int r = lower_bound(heights.begin(),end(heights),x[0]+x[1])-begin(heights);
            l--;
            add(l,r,x[1],maxi,maxh);
            ans.push_back(maxh);
        }
        return ans;
    }
};