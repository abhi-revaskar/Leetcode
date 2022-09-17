class Solution {
    const int mod = 1e9+7;
public:
    void mark(int xl,int xr,int yb,int yt,vector<vector<int>>& mat)
    {
        for(int i=xl;i<xr;i++)
        {
            for(int j=yb;j<yt;j++)
                mat[j][i] = 1;
        }
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> x,y;
        for(auto p:rectangles)
        {
            x.push_back(p[0]);
            x.push_back(p[2]);
            y.push_back(p[1]);
            y.push_back(p[3]);
        }
        sort(begin(x),end(x));
        x.erase(unique(begin(x),end(x)),end(x));
        sort(begin(y),end(y));
        y.erase(unique(begin(y),end(y)),end(y));
        vector<vector<int>> mat(y.size(),vector<int> (x.size(),0));
        for(auto p:rectangles)
        {
            int xl = lower_bound(begin(x),end(x),p[0])-begin(x);
            int xr = lower_bound(begin(x),end(x),p[2])-begin(x);
            int yb = lower_bound(begin(y),end(y),p[1])-begin(y);
            int yt = lower_bound(begin(y),end(y),p[3])-begin(y);
            mark(xl,xr,yb,yt,mat);
        }
        long long ans = 0;
        for(int i=0;i<y.size()-1;i++)
        {
            for(int j=0;j<x.size()-1;j++)
            {
                // cout<<mat[i][j]<<" ";
                ans+=(mat[i][j]*1LL*(x[j+1]-x[j]))*(y[i+1]-y[i]);
                ans%=mod;
            }
            // cout<<endl;
        }
        return ans%mod;
    }
};