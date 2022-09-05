class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n/2;i++)
        {
            int l=i,r=n-1-i,t=i,b=n-1-i;
            while(l<r)
            {
                int temp = matrix[t][l];
                matrix[t][l] = matrix[n-1-l][t];
                matrix[n-1-l][t] = matrix[b][n-1-l];
                matrix[b][n-1-l] = matrix[l][r];
                matrix[l][r] = temp;
                l++;
            }
        }
    }
};