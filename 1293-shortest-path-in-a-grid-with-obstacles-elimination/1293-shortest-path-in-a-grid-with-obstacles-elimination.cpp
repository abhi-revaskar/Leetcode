class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,-1));
        queue<vector<int>> q;
        // vis[0][0] = k;
        q.push({0,0,0,k}); //x,y,len,k
        while(!q.empty())
        {
            auto t = q.front();q.pop();
            int x = t[0],y=t[1];
            if(x<0 || y<0 || x==n || y==m) //out of bound
                continue;
            if(x==n-1 && y==m-1) //reached destn
                return t[2];
            if(grid[x][y]) //obstacle
            {
                if(t[3])
                    t[3]--; //can remove this
                else
                    continue; //cant remove this
            }
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue; //can reach this cell with higher val of k, preferable
            //not visited or reached with lower val of k
            vis[x][y] = t[3];
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
        }
        return -1;
    }
};