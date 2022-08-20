class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dist,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto point = points[pq.top().second];
            pq.pop();
            ans.push_back(point);
        }
        return ans;
    }
};