class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int n = img1.size();
        int cnt=0;
        for(int i=r;i<n;i++)
        {
            for(int j=c;j<n;j++)
            {
                if(img2[i][j]==img1[i-r][j-c] && img2[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1.size();j++)
            {
                ans = max(ans,solve(i,j,img1,img2));
                ans = max(ans,solve(i,j,img2,img1));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(img1[i][j],img1[j][i]);
                swap(img2[i][j],img2[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(img1[i][j],img1[i][n-j-1]);
                swap(img2[i][j],img2[i][n-j-1]);
            }
        }
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1.size();j++)
            {
                ans = max(ans,solve(i,j,img1,img2));
                ans = max(ans,solve(i,j,img2,img1));
            }
        }
        return ans;
    }
};