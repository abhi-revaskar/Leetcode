class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxi = startFuel,ans = 0;
        stations.push_back({target,0});
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<stations.size()-1;i++)
        {
            // cout<<maxi<<" "<<stations[i][0]<<" "<<stations[i][1]<<endl;
            if(stations[i][0]<=maxi)
                pq.push({stations[i][1],stations[i][0]});
            while(!pq.empty() && maxi<stations[i+1][0])
            {
                ans++;
                maxi+=pq.top().first;
                pq.pop();
            }
            if(maxi>=target)
                return ans;
        }
        if(maxi<target)
            return -1;
        return ans;
    }
};