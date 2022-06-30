class Solution {
public:
    void dfs(int sr,int sc,int old,int color,vector<vector<int>> &img)
    {
        if(sr<0 || sr>=img.size() || sc<0 || sc>= img[0].size() || img[sr][sc]!=old) 
            return;
        img[sr][sc] = color;
        dfs(sr+1,sc,old,color,img);
        dfs(sr-1,sc,old,color,img);
        dfs(sr,sc+1,old,color,img);
        dfs(sr,sc-1,old,color,img);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if(old!=color)
        {
            dfs(sr,sc,old,color,image);
        }
        return image;
    }
};