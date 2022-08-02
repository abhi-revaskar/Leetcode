class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dirs{-1,0,1};
        if(grid[0][0]==1 || grid.back().back()==1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int depth=1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i==n-1 && j==n-1)
                    return depth;
                for(auto row:dirs)
                {
                    for(auto col:dirs)
                    {
                        if(i+row>=0 && i+row<n && j+col>=0 && j+col<n && grid[i+row][j+col]==0)
                        {
                            grid[i+row][j+col]=1;
                            q.push({i+row,j+col});
                        }
                    }
                }
            }
            depth++;
        }
        if(n==1)
            return 1;
        return -1;
    }
};