class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        if(n==1 || m==1)
            return true;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<m && i+j<n;j++)
            {
                if(matrix[i+j][j]!=matrix[i+j-1][j-1])
                    return false;
            }
        }
        for(int j=1;j<m;j++)
        {
            for(int i=1;i<n && i+j<m;i++)
                if(matrix[i][j+i]!=matrix[i-1][j+i-1])
                    return false;
        }
        return true;
    }
};