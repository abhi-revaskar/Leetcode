class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dist,i});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            auto point = points[pq.top().second];
            pq.pop();
            ans.push_back(point);
        }
        return ans;
    }
};