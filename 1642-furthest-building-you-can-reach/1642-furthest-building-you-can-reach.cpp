class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<n;i++)
        {
            if(heights[i]<=heights[i-1])
                continue;
            int jump = heights[i]-heights[i-1];
            pq.push(jump);
            if(pq.size()>ladders)
            {
                if(pq.top()>bricks)
                    return i-1;
                bricks-=pq.top();
                pq.pop();
            }
        }
        return n-1;
    }
};