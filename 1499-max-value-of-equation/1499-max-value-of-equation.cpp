class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        priority_queue<vector<int>> q;
        q.push({points[0][1]-points[0][0],points[0][0]});
        for(int i=1;i<points.size();i++)
        {
            auto point = points[i];
            while(!q.empty() && (point[0] - q.top()[1])>k)
                q.pop();
            if(!q.empty())
                ans = max(ans,abs(point[0]-q.top()[1])+q.top()[0]+q.top()[1]+point[1]);
            q.push({point[1]-point[0],point[0]});
        }
        return ans;
    }
};