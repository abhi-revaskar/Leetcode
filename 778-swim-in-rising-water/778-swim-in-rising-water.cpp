class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,10000));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty())
        {
            auto top = pq.top();pq.pop();
            int i=top.second.first,j=top.second.second,time=top.first;
            if(i>0 && max(time,grid[i-1][j])<dist[i-1][j])
            {
                dist[i-1][j] = max(grid[i-1][j],time);
                pq.push({dist[i-1][j],{i-1,j}});
            }
            if(i<n-1 && max(grid[i+1][j],time)<dist[i+1][j])
            {
                dist[i+1][j] = max(grid[i+1][j],time);
                pq.push({dist[i+1][j],{i+1,j}});
            }
            if(j>0 && max(grid[i][j-1],time)<dist[i][j-1])
            {
                dist[i][j-1] = max(grid[i][j-1],time);
                pq.push({dist[i][j-1],{i,j-1}});
            }
            if(j<n-1 && max(grid[i][j+1],time)<dist[i][j+1])
            {
                dist[i][j+1] = max(grid[i][j+1],time);
                pq.push({dist[i][j+1],{i,j+1}});
            }
        }
        // for(auto x:dist)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        return dist.back().back();
    }
};