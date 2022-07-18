class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                matrix[i][j]+=matrix[i][j-1];//prefix sum for each row
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++) //for each pair of columns
            {
                unordered_map<int,int> mp;
                mp[0]=1;
                int sum = 0;
                for(int k=0;k<n;k++) //all the submatrices between these two columns
                {
                    sum+=matrix[k][j]-(i>0? matrix[k][i-1]:0);
                    if(mp.count(sum-target))
                        ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};