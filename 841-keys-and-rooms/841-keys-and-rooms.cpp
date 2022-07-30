class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &rooms)
    {
        vis[i]=1;
        for(auto x:rooms[i])
        {
            if(!vis[x])
                dfs(x,vis,rooms);
        }
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        dfs(0,vis,rooms);
        for(auto x:vis)
            if(x==0)
                return false;
        return true;
    }
};