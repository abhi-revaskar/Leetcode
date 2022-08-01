class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dist = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i>0 && ans[i-1][j]==-1)
                {
                    ans[i-1][j]=dist;
                    q.push({i-1,j});
                }
                if(j>0 && ans[i][j-1]==-1)
                {
                    ans[i][j-1]=dist;
                    q.push({i,j-1});
                }
                if(i<n-1 && ans[i+1][j]==-1)
                {
                    ans[i+1][j]=dist;
                    q.push({i+1,j});
                }
                if(j<m-1 && ans[i][j+1]==-1)
                {
                    ans[i][j+1]=dist;
                    q.push({i,j+1});
                }
            }
            dist++;
        }
        return ans;
    }
};