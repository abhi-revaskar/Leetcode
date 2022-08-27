class Solution {
public:
    bool atlant(int i,int j,int k,vector<vector<int>> &h)
    {
        if(i==h.size() || j==h[0].size())
            return true;
        if(i==-1 || j== -1 || h[i][j]>k)
            return false;
        int a = h[i][j];
        h[i][j]=INT_MAX;
        bool ans = false;
        ans = ans || atlant(i-1,j,a,h);
        ans = ans || atlant(i+1,j,a,h);
        ans = ans || atlant(i,j-1,a,h);
        ans = ans || atlant(i,j+1,a,h);
        h[i][j] = a;
        return ans;
    }
    bool pacific(int i,int j,int k,vector<vector<int>> &h)
    {
        if(i==-1 || j==-1)
            return true;
        if(i==h.size() || j==h[0].size() || h[i][j]>k)
            return false;
        int a = h[i][j];
        h[i][j]=INT_MAX;
        bool ans = false;
        ans = ans || pacific(i-1,j,a,h);
        ans = ans || pacific(i+1,j,a,h);
        ans = ans || pacific(i,j-1,a,h);
        ans = ans || pacific(i,j+1,a,h);
        h[i][j] = a;
        return ans;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> ans;
        int n = h.size(),m=h[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific(i,j,h[i][j],h) && atlant(i,j,h[i][j],h))
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
