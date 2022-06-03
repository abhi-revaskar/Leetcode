class NumMatrix {
public:
    vector<vector<int>> a,sum;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        a=matrix;
        n=a.size();
        m=a[0].size();
        sum.resize(n);
        for(int i=0 ; i<n ;i++)
        {
            int s=0;
            for(int j=0;j<m;j++)
            {
                s+=a[i][j];
                sum[i].push_back(s);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;i++)
        {
            ans+=sum[i][col2]-(col1==0?0:sum[i][col1-1]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */