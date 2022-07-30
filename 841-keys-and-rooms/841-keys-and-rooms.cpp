class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
        stack<int> st;
        st.push(0);
        vis[0]=1;
        while(!st.empty())
        {
            int node = st.top();st.pop();
            for(auto x:rooms[node])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    st.push(x);
                }
            }
        }
        for(auto x:vis)
            if(x==0)
                return false;
        return true;
    }
};