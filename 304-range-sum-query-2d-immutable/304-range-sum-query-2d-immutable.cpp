class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j = 1;j<m;j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        a = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1;i<=row2;i++)
            ans+=a[i][col2]-(col1>0?a[i][col1-1]:0);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */