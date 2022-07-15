class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        int last_interval = 0;
        for(int i=1;i<intervals.size();i++)
        {
            int start = intervals[i][0],end = intervals[i][1];
            if(intervals[last_interval][1]>start)
            {
                if(end<intervals[last_interval][1])
                    last_interval = i;
                ans++;
            }
            else
                last_interval = i;
        }
        return ans;
    }
};