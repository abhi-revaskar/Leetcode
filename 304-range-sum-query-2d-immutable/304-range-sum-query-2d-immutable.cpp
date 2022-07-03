class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        a=matrix;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(i==0)
                {
                    if(j==0)
                        a[i][j]=matrix[i][j];
                    else
                        a[i][j]= a[i][j-1]+matrix[i][j];
                }
                else if(j==0)
                    a[i][j]=a[i-1][j]+matrix[i][j];
                else
                {
                    a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        int up = row1>0?a[row1-1][col2]:0;
        int left = col1>0? a[row2][col1-1] :0;
        int upleft = (row1>0 && col1>0)?a[row1-1][col1-1]:0;
        ans = a[row2][col2] - up  - left + upleft;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */