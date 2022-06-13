class Solution {
public:
   void  solve(vector<vector<int>>& ans,int r, int c, int clr,int old)
    {
        if(r<0 || r>= ans.size() || c<0 || c>ans[0].size())
            return;
        if(ans[r][c]==old)
        {
            ans[r][c]=clr;
            solve(ans,r+1,c,clr,old);
            solve(ans,r-1,c,clr,old);
            solve(ans,r,c-1,clr,old);
            solve(ans,r,c+1,clr,old);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old=image[sr][sc];
        if(old!= newColor)
        solve(image,sr,sc,newColor,old);
        return image;
    }
};