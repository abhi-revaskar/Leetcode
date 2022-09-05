class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(),m = matrix[0].size();
        int t = 0,b = n-1,l = 0, r = m-1;
        while(true)
        {
            for(int i=l;i<=r;i++)
                ans.push_back(matrix[t][i]);
            t++;
            if(t>b)
                break;
            for(int i = t;i<=b;i++)
                ans.push_back(matrix[i][r]);
            r--;
            if(r<l)
                break;
            for(int i=r;i>=l;i--)
                ans.push_back(matrix[b][i]);
            b--;
            if(b<t)
                break;
            for(int i=b;i>=t;i--)
                ans.push_back(matrix[i][l]);
            l++;
            if(l>r)
                break;
        }
        return ans;
    }
};