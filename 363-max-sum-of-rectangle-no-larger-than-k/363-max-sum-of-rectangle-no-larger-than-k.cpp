class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),m = matrix[0].size(),ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        for(int col1=0;col1<m;col1++)
        {
            for(int col2=col1;col2<m;col2++)
            {
                set<int> s;
                s.insert(0);
                int sum = 0;
                for(int row = 0;row<n;row++)
                {
                    int x = matrix[row][col2]-(col1>0?matrix[row][col1-1]:0);
                    sum+=x;
                    if(sum==k)
                        return k; //first opt
                    auto it = s.lower_bound(sum-k);
                    if(it!=s.end())
                    {
                        ans = max(ans,sum-*it);
                    }
                    s.insert(sum);
                }
            }
        }
        return ans;
    }
};