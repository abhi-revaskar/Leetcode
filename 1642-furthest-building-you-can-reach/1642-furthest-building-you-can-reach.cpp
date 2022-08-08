class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if(n==1)
            return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]<=heights[i-1])
                continue;
            int jump = heights[i]-heights[i-1];
            if(pq.size()<ladders)
                pq.push(jump);
            else if(pq.size())
            {
                if(pq.top()<jump)
                {
                    if(pq.top()>bricks)
                        return i-1;
                    bricks-=pq.top();
                    pq.pop();
                    pq.push(jump);
                }
                else
                {
                    if(jump>bricks)
                        return i-1;
                    bricks-=jump;
                }
            }
            else if(jump>bricks)
                return i-1;
            else
                bricks-=jump;
        }
        return n-1;
    }
};